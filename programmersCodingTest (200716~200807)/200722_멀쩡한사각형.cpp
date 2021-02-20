using namespace std;

long long solution(int w,int h) {
    
    // Find GCF
	long long a = (long long)w, b = (long long)h, c = 1, gcf = 1;
    if(h > w){
        a = h;
        b = w;
    }
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	gcf = a;
    
    // Find number of tore rectangle in small unit
    /* 
       width = w/gcf, height = h/gcf
       The diagonal of small unit doesn't cross the grid because width and height are coprime
       So it always makes width + height - 1 tore rectangle
    */
    long long num_tore = (w/gcf) + (h/gcf) - 1;
    long long answer = w * h - gcf * num_tore;
    return answer;
}
