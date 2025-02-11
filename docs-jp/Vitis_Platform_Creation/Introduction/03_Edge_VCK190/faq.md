<!--
# Copyright 2020 Xilinx Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
-->

<p align="right"><a href="../../../README.md">English</a> | <a>日本語</a></p>

<table width="100%">
 <tr width="100%">
    <td align="center"><img src="https://japan.xilinx.com/content/dam/xilinx/imgs/press/media-kits/corporate/xilinx-logo.png" width="30%"/><h1>Versal カスタム プラットフォーム作成チュートリアル</h1>
    </td>
 </tr>
</table>

## よくある質問

### プラットフォームがハードウェアでブートできないのはなぜですか。

Versal プラットフォームにはさまざまなブート段階があります。トラブルシューティングの詳細を確認するには、まず問題のある段階を特定する必要があります。

- **ザイリンクス Versal プラットフォーム ローダーおよびマネージャー (PLM)** 段階の問題の場合、PDI ファイルをロードし、各コンポーネントを初期化します。この段階が停止するか、エラーが表示される場合は、Vivado の設定を確認してください。
- ブートが U-Boot 段階で停止する場合は、デバイス ツリーの設定を確認してください。SD カード回路が高速をサポートしない場合は、SD コントローラー ノードに no-1-8-v を追加してください。U-Boot は、SD ブートモードの場合、SD カードの fat32 パーティションで boot.scr と system.dtb を検索します。これら 2 つのファイルが使用可能であることを確認してください。

### プラットフォームがハードウェア エミュレーションでブートできないのはなぜですか。

- CIPS、NOC、および AI エンジンの場合、SELECTED\_SIM\_MODEL が TLM に設定されていることを確認してください。

### AIE アプリケーションと PL カーネルはいつプログラムされますか。

作成するプラットフォームは DFX プラットフォームではないため、PL カーネルは常にインプリメントされ、プラットフォームと一緒にパッケージされます。これらは BOOT.BIN に含まれ、ブート時にハードウェアにダウンロードされます。

ホストアプリケーションを起動すると、xclbin ファイルからカーネル メタデータを読み取り、カーネル トポロジとパラメーターを理解します。この段階では、PL ビットストリームはコンフィギュレーションされません。

AI エンジンには、ブート中にコンフィギュレーションする方法と、ホスト アプリケーションでグラフをロードする方法の 2 つの実行方法があります。

### AIE システム アプリケーションが停止するのはなぜですか。

PL + AIE システム アプリケーションでプラットフォームをテストし、ボード上で次のエラー メッセージが表示されて停止した場合、Ctrl + C を押すとコマンドが停止します。**package** ディレクトリで、**package\_no\_aie\_debug** ディレクトリではなく、 **package** を使用している可能性があます。package ディレクトリ内のアプリケーションは、デバッグに使用されます。読み込み後に停止し、デバッガーが接続するのを待ちます。

```
[   52.262013] [drm] Pid 715 opened device
[   52.265891] [drm] Pid 715 closed device
[   52.299093] [drm] Pid 715 opened device
[   52.302958] [drm] Pid 715 closed device
[   52.307012] [drm] Pid 715 opened device
Loading: 'binary_container_1.xclbin'
[   52.579320] [drm] zocl_xclbin_read_axlf fbc72c83-5ab0-43f2-97aa-60c7672e835a ret: 0
[   52.584870] [drm] bitstream fbc72c83-5ab0-43f2-97aa-60c7672e835a locked, ref=1
[   52.592572] [drm] No ERT scheduler on MPSoC, using KDS
[   52.604924] [drm] Interrupt is not enabled for at least one kernel. Fall back to polling mode  .
[   52.604934] [drm] 12 non-zero interrupt-id CUs out of 13 CUs
[   52.613562] [drm] CU ffffff02 is free-running.
[   52.619222] [drm] scheduler config ert(0)
[   52.623663] [drm]   cus(3)
[   52.627666] [drm]   slots(16)
[   52.630369] [drm]   num_cu_masks(1)
[   52.633330] [drm]   cu_shift(16)
[   52.636807] [drm]   cu_base(0xa4010000)
[   52.640030] [drm]   polling(1)
[   52.643894] [drm] bitstream fbc72c83-5ab0-43f2-97aa-60c7672e835a unlocked, ref=0
^C[   52.654496] [drm] bitstream fbc72c83-5ab0-43f2-97aa-60c7672e835a locked, ref=1
[   56.707230] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   57.241186] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   57.753177] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   58.265177] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   58.777175] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   60.313187] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   60.825177] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   61.337174] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   61.849185] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   62.361191] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   62.873190] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   63.385190] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   63.897188] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   64.409185] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   64.921183] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   65.433177] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   65.945174] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   66.457185] [drm] pid(715) waiting for outstanding 1 cmds to finish
[   66.969193] [drm:zocl_client_release [zocl]] *ERROR* Please investigate stale cmds
[   66.983017] [drm] addr 0xa4020000, status 0x4
[   66.983019] [drm] addr 0xa4010000, status 0x1
[   66.987375] [drm] bitstream fbc72c83-5ab0-43f2-97aa-60c7672e835a unlocked, ref=0
[   66.991728] [drm] Pid 715 closed device

```

<p align="center"><sup>Copyright&copy; 2020 Xilinx</sup></p>
<p align="center"><sup>この資料は 2021 年 2 月 8 日時点の表記バージョンの英語版を翻訳したもので、内容に相違が生じる場合には原文を優先します。資料によっては英語版の更新に対応していないものがあります。
日本語版は参考用としてご使用の上、最新情報につきましては、必ず最新英語版をご参照ください。</sup></p>
