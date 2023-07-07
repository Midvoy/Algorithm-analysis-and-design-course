# Seam Carving 算法实现

## 安装

安装python3

## 依赖项
opencv-python
numpy

## 运行
在命令行跳转到相应路径下，然后安装下面依赖项
pip install opencv-python
pip install numpy
把想要处理的图片命名为"image1.jpg"放入与.py文件相同路径下
运行
python main.py
等待结果，根据图像大小可能需要3-10分钟处理时间
## 输出

输出图像到：
./image1_result.jpg

## 时空复杂度分析
在seam_carving中
首先处理energy_map得到能量图，时空复杂度均为M*N
每次循环处理并删除一条seam，共循环（图片的宽度-目标图片的宽度）次作为外层循环。
每次找出一条seam需要遍历图中所有像素一遍进行dp，时空复杂度均为M*N
删除seam时将seam路径上往后的所有像素前移一格最后删除最后一列，时空复杂度均为M*N
因此再算上外层循环
总的时间复杂度为O(M*N*N)即O(M*N^2)
空间复杂度为O(M*N)
其中M为图片的长，N为宽

