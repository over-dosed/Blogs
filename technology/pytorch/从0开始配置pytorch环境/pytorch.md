# 从0开始安装pytorch环境

## 背景

之前frp配好了内网穿透ssh连接实验室电脑，但是发现python环境没有。。无奈下只好重新配置conda 的pytorch环境，
实验室电脑貌似已经装好了显卡驱动，cuda版本11.4也已经配好，所以应该只是用命令行安装conda 和 pytorch就好了。

### 安装miniconda3

1. 创建miniconda目录，cd到该目录
   ![20220108140928](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108140928.png)

2. 在linux在使用以下命令下载miniconda

~~~
wget -c https://mirrors.tuna.tsinghua.edu.cn/anaconda/miniconda/Miniconda3-latest-Linux-x86_64.sh
~~~

![20220108140955](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108140955.png)

3. 安装刚刚下载的Miniconda，bash就是运行.sh文件的意思

~~~
bash Miniconda3-latest-Linux-x86_64.sh
~~~

一路运行enter下去，最后yes接收条款，修改安装目录
miniconda会自动修改config ：

~~~
conda config --set auto_activate_base false
~~~

于是执行以下命令:

~~~
conda config --set auto_activate_base true
~~~

4. 重启shell，发现前面出现（base），说明环境安装成功

![20220108141759](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108141759.png)

5. 添加清华源镜像

~~~
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free

conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge

conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/bioconda

conda config --set show_channel_urls yes
~~~

显示源使用如下命令：

~~~
conda config --show-sources
~~~

![20220108142111](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108142111.png)

## cuda

1. 刚开始的时候发现cuda11.4是已经安装完成的，但是在输入nvcc -V指令后输出如下：
    ![20220108144414](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108144414.png)

~~于是开始安装 nvidia-cuda-toolkit~~ **不要这样做**
安装完成后，查看nvcc和显卡信息：
![20220108145151](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108145151.png)

发现cuda 装了9.1的版本，只能重装cuda

无奈卸载nvidia-cuda-toolkit

~~~
sudo apt-get remove  nvidia-cuda-toolkit
sudo apt autoremove
sudo apt-get remove cuda*
~~~

卸了很多东西。。

2. 接着去cuda官网获取安装指令，挑选合适的版本
<https://developer.nvidia.com/cuda-11-3-1-download-archive?target_os=Linux&target_arch=x86_64&Distribution=Ubuntu&target_version=18.04&target_type=runfile_local>

![20220108151358](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108151358.png)

~~~
wget https://developer.download.nvidia.com/compute/cuda/11.3.1/local_installers/cuda_11.3.1_465.19.01_linux.run
sudo sh cuda_11.3.1_465.19.01_linux.run
~~~

**安装的时候没有选择安装驱动，会出现问题**

3. 执行完上述命令
![20220108175830](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108175830.png)

显示缺失一些必要库，同时需要修改~~环境变量~~（path吧）
网上找的安装必要库：

~~~
sudo apt-get install freeglut3-dev build-essential libx11-dev libxmu-dev libxi-dev libgl1-mesa-glx libglu1-mesa libglu1-mesa-dev
~~~

修改环境变量：

~~~
export PATH=/usr/local/cuda-11.3/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/cuda11.3/lib64
source /etc/profile
~~~

网络不好没代理下载真的很慢
我是用腾讯云的对象存储拷过去的，结果中途又出现了错误：

### kex_exchange_identification: read: Connection reset

最后根据<https://www.cnblogs.com/lfri/p/15257145.html>
总结，vscode偶尔在断开其他所有ssh连接后能连上，启动vscode里面的终端，开始配置hosts.allow
最后重启。
![20220108163437](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108163437.png)
解决

### 结果

~~~
nvcc -V
~~~

![20220108181307](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108181307.png)

## conda环境配置

1. 查看当前环境：

   ~~~
   conda env list
   ~~~

   ![20220108142245](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108142245.png)

2. 新建环境

~~~
conda create -n pytorch python=3.9 -y
conda activate pytorch
~~~

![20220108184500](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108184500.png)

3. 安装pytorch

~~~
conda install pytorch torchvision torchaudio cudatoolkit=11.3 -c pytorch
~~~

![20220108184829](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108184829.png)

下了很久很久。。。

最后mkl文件还是无法下载，通过报错得到的url：
<https://repo.anaconda.com/pkgs/main/linux-64/mkl-2021.4.0-h06a4308_640.conda>
获取.conda文件安装包，然后移动到

~~~
 /home/zxy/miniconda/miniconda3/pkgs/mkl-2021.4.0-h06a4308_640.conda
~~~

路径，再使用指令：

~~~
 conda install --use-local mkl-2021.4.0-h06a4308_640.conda
~~~

最后再次安装pytorch,成功

## 解决cuda.avilable问题

![20220108234457](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108234457.png)

可以看见输出了false , 使用
![20220108234541](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108234541.png)
输出为0

首先通过warning报错推断出cuda_visible的问题，修改如下：
![20220108234645](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220108234645.png)

### 解决方法

~~~
apt-get install nvidia-modprobe
~~~
<https://blog.csdn.net/llh_1178/article/details/115653794>
绝了！

![20220109003024](https://picture-1308922338.cos.ap-guangzhou.myqcloud.com/note/20220109003024.png)

# 成功解决
