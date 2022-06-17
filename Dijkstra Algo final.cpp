#include <stdio.h>
#include <conio.h>
#define N 5 //asumsikan dulu ada 5 buah titik yang ada di dalam kota
#define LIM 999
int main(){
	int matriks[N][N]; //menampung matriks tetangga
	int asal; //menentukan titik awal untuk menentukan jarak
	int tempMatriks[N][N]; //variabel yang akan menyimpan nilai matrik yang sudah dilakuan modifikasi dengan nilai LIM
	int jarak[N]; // menampung jarak dari node asal ke node yang lain
	int temp[N]; 
	int visit[N];//menentukan apakah node sudah dikunjugi atau blm    
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("ketik jarak titik %d dengan titik %d (dalam km) : ", i + 1, j + 1);
			scanf("%d", &matriks[i][j]); //memasukan bobot antar vertex
		}
	}
	printf("ketik titik asal anda mengirim : "); //masukan node awal / posisi awal
	scanf("%d",&asal);
	printf("==========================================\n");  
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(matriks[i][j] == 0){
				tempMatriks[i][j] = LIM; //inisiasi dengan nilai LIM jika bobot matriks[i][j] bernilai 0
			}else{
				tempMatriks[i][j] = matriks[i][j]; // jika tidak bernilai 0 maka simpan di dalam tempMatriks
			}
		}
	}
	for(int i = 0; i < N; i++){
		jarak[i] = tempMatriks[asal][i]; // berisikan jarak node asal dengan node ke i 
		temp[i] = asal; // tampung nilai node asal ke dalam variabel temp
		visit[i] = 0; //menandakan bahwa belum sempat dikunjungi; 

	}
	jarak[asal] = 0;  // inisialisasi jarak[awal] dengan nilai 0 sebagai indikasi tidak adanya gelang
	visit[asal] = 1;  // inisialisasi visit[awal] dengan nilai 1 sebagai indikasi node sudah pernah dikunjungi
	int hitung_node = 1; // inisialisasi variabel hitung node karene node asal sudah dikunjungi sehingga hitung node bernilai 1
	int jarak_min , next_node;
	int nextvertex;
	while(hitung_node < N - 1){
		jarak_min = LIM; 
		for(int i = 0; i < N; i++){
			if(jarak[i] < jarak_min && visit[i] != 1){ // jika memnuhi kondisi ini maka lakukan perintah yang ada di dalamnya 
				jarak_min = jarak[i]; // tampung jarak[i] ke dalam jarak_min
				nextvertex = i; //kemudian program akan memilih vertex ke yang menjadi pilihan dalam jarak_min untuk menjadi acuan yang baru
			}
		}
		visit[nextvertex]  = 1; // vertex yang menjadi acuan yang baru diisi nilai nya dengan 1 yang menandakan sudah dikunjungi 
		for(int i = 0; i < N; i++){
			if(visit[i] != 1){
				if(jarak_min + tempMatriks[nextvertex][i] < jarak[i]){ //bandingkan hasil penjumalahan jarak antar node dengan nilai yang ada di dalam array jarak
					jarak[i] = jarak_min + tempMatriks[nextvertex][i];
					temp[i] = nextvertex; // menyimpan semua node yang jika terhubung akan menghasilkan jarak minimum dari lintasan awal ke lintasan yang dituju 
				}
			}
		}
		hitung_node++; 
	}
	int a[N+1], k, j; 
	for(int i = 0; i < N; i++){
		if(i != asal){ //menampilkan jarak sebuah node dengan node yang lain disertai dengan jalur yang harus dilalui 
			printf("jarak titik asal %d ke titik %d adalah : %d\n", asal, i, temp[i]);
			printf("jalur yang harus ditempuh : "); 
			j = i;
			printf("%d <- ", i);
			while(j != asal){
				j = temp[j]; // variabel temp sebagai variabel yang menyimpan vertex yang terpilih menjadi nextvertex
				printf("%d", j); 
				if(j != asal){
					printf("<-"); 
				}
			}
			printf("\n");
		}
	}
	printf("jarak titik asal %d ke titik %d adalah : %d\n", asal, N - 1, jarak[N-1]); 
	getch(); 
	return 0; 
}
