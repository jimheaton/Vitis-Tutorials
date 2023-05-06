/**********
© Copyright 2020 Xilinx, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
**********/

#include <fstream>
#include <cstring>
#include "data.h"

#include "xrt/experimental/xrt_kernel.h"
#include "experimental/xrt_graph.h"

static std::vector<char>
load_xclbin(xrtDeviceHandle device, const std::string& fnm)
{
	if (fnm.empty())
		throw std::runtime_error("No xclbin specified");

	// load bit stream
	std::ifstream stream(fnm);
	stream.seekg(0,stream.end);
	size_t size = stream.tellg();
	stream.seekg(0,stream.beg);

	std::vector<char> header(size);
	stream.read(header.data(),size);

	auto top = reinterpret_cast<const axlf*>(header.data());
	if (xrtDeviceLoadXclbin(device, top))
		throw std::runtime_error("Xclbin loading failed");

	return header;
}

#define SAMPLES 256

int main(int argc, char ** argv)
{
	//////////////////////////////////////////
	// Open xclbin
	//////////////////////////////////////////
	char* xclbinFile=argv[1];
	auto device = xrt::device(0);
    	if(device == nullptr)
		throw std::runtime_error("No valid device handle found. Make sure using right xclOpen index.");
    	auto xclbin_uuid = device.load_xclbin(xclbinFile);

	int sizeIn = SAMPLES/2;
	int sizeOut = SAMPLES;
	
	//////////////////////////////////////////
	// input memory
	// Allocating the input size of sizeIn to MM2S
	// This is using low-level XRT call xclAllocBO to allocate the memory
	//////////////////////////////////////////	
    
	auto in_bohdl = xrt::bo(device, sizeIn * sizeof(int16_t) * 2, 0, 0);
	auto in_bomapped = in_bohdl.map<uint32_t*>();
	memcpy(in_bomapped, cint16Input, sizeIn * sizeof(int16_t) * 2);
	printf("Input memory virtual addr 0x%px\n", in_bomapped);

	in_bohdl.sync(XCL_BO_SYNC_BO_TO_DEVICE);	
	//////////////////////////////////////////
	// output memory
	// Allocating the output size of sizeOut to S2MM
	// This is using low-level XRT call xclAllocBO to allocate the memory
	//////////////////////////////////////////
	
	auto out_bohdl = xrt::bo(device, sizeOut * sizeof(int), 0, 0);
	auto out_bomapped = out_bohdl.map<uint32_t*>();
	memset(out_bomapped, 0xABCDEF00, sizeOut * sizeof(int));
	printf("Output memory virtual addr 0x%px\n", out_bomapped);
	//////////////////////////////////////////
	// mm2s ip
	// Using the xrtPLKernelOpen function to manually control the PL Kernel
	// that is outside of the AI Engine graph
	//////////////////////////////////////////

	auto mm2s_khdl = xrt::kernel(device, xclbin_uuid, "mm2s");
	auto mm2s_rhdl = mm2s_khdl(in_bohdl, nullptr, sizeIn);
	printf("run mm2s\n");
	//////////////////////////////////////////
	// s2mm ip
	// Using the xrtPLKernelOpen function to manually control the PL Kernel
	// that is outside of the AI Engine graph
	//////////////////////////////////////////
	
	auto s2mm_khdl = xrt::kernel(device, xclbin_uuid, "s2mm");
	auto s2mm_rhdl = s2mm_khdl(out_bohdl, nullptr, sizeOut);
	printf("run s2mm\n");
	//////////////////////////////////////////
	// graph execution for AIE
	//////////////////////////////////////////	
        auto cghdl = xrt::graph(device,xclbin_uuid,"clipgraph");	
	
	printf("graph run\n");
	cghdl.run(1);
	
	cghdl.end();
	printf("graph end\n");
	
	//////////////////////////////////////////
	// wait for mm2s done
	//////////////////////////////////////////	
	
	mm2s_rhdl.wait();
	//////////////////////////////////////////
	// wait for s2mm done
	//////////////////////////////////////////	
	
	s2mm_rhdl.wait();

	out_bohdl.sync(XCL_BO_SYNC_BO_FROM_DEVICE);
	//////////////////////////////////////////
	// Comparing the execution data to the golden data
	//////////////////////////////////////////	
	
	int errorCount = 0;
	{
		for (int i = 0; i < sizeOut; i++)
		{
				if ((signed)out_bomapped[i] != golden[i])
				{
					printf("Error found @ %d, %d != %d\n", i, out_bomapped[i], golden[i]);
					errorCount++;
				}
		}

		if (errorCount)
			printf("Test failed with %d errors\n", errorCount);
		else
			printf("TEST PASSED\n");
	}
	
	return errorCount;
}
