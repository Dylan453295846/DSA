# 排序问题（升序）

### 选择排序(n^2)

- 找出最小元素，放在最array[0], 接着找次小元素与array[1]交换，对array中前n个元素执行即可.

### 冒泡排序(n^2)

- 反复交换相邻的未按次序排列的元素

### 插入排序(n^2)

- 依次从数组中取出元素，与已经排好顺序的数组比较，插入符合位置

### 归并排序(nlgn)-递归-非原址

- 分解：将n个元素的序列arr[] 分成各具n/2个元素的子序列
- 解决：使用归并排序递归地排序两个子序列
- 合并：假设两个子序列已经分别有序，从两个子序列最上面依次取较小的放在arr[]上

### 快速排序(nlgn)-递归-原址

- 分解：找到一个主元（可随机，可定），按主元大小，把比主元大的元素放在一个子数组中，比主元小的放在另一子数组中（仍然在原数组中，只是调换顺序，把数组分块）
- 解决：通过递归调用快速排序，因为子数组是原址排序，不需要合并操作

### 堆排序(nlgn)-最大堆

- 只包含堆用数组初始化一个堆，建堆，维护，堆排序
  - 堆的维护：递归、维护最大堆性质（逐级下降）
  - 建堆：对完全二叉树的n/2个内部结点进行维护
  - 堆排序：每次从堆中选取最大元素，再重新维护堆
- 优先队列：插入，最大值，去掉并返回最大值，增加元素的关键字值
  - 增加元素的关键字值：增加并调整与其父节点的位置
  - 插入：增加堆的大小，初始化新元素为负无穷，再增加到插入的关键字

### Tips

- 原址排序：仅有常数个元素需要重新开辟存储空间
- 统计时间