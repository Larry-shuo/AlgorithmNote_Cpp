1.堆的定义及操作
//默认大顶堆
    (1)向下调整
        void downAdjust(int low,int high){//low为欲调整节点下标,high一般为最后一个元素下标
            int i=low,j=i*2;
            while(j<=high){
                if(j+1<=high && heap[j+1]>heap[j])//选出左右孩子的较大者
                    j=j+1;
                if(heap[j]>heap[i]){//若孩子大于自己
                    swap(heap[j],heap[i]);  //交换
                    i=j;    //继续向下调整
                    j=i*2;
                }
                else{
                    break;
                }
            }
        }
    (2)建堆(已存在数据)
        void createHeap(){
            for(int i=n/2;i>=1;i==)//从最后一个非叶节点开始，向上走
                downAdjust(i,n);
        }
    (3)删除堆顶元素
        void deleteTop(){
            heap[1]=heap[n--];
            downAdjust(1,n);
        }
    (4)添加元素
    //添加至末尾,不断向上调整
        void upAdjust(int low,int high){
            int i=high,j=i/2;
            while(j>=low){
                if(heap[j]<heap[i]){
                    swap(heap[i],heap[j]);
                    i=j;
                    j=i/2;
                }
                else{
                    break;
                }
            }
        }
        void insert(int x){
            heap[n++]=x;
            upAdjust(1,n);
        }
    2.堆排序
        void heapsort(){
            createheap();
            for(int i=n;i>1;i--){
                swap(heap[1],heap[i]);
                downAdjust(1,i-1);
            }
        }