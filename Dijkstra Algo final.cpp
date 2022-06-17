#include <bits/stdc++.h>
using namespace std;
int jarak_vertex[20][20]; //mendeklarasikan jarak antara satu vertex dengan vertex yang lain
int vertex;
int minimum_vertex(int jarak[], bool dikunjungi[]){
	int node; 
	int min = INT_MAX; //mengisi variabel min dengan nilai maksimal dari integer yaitu sekitar 2 milyar
	for(int i = 0; i < vertex; i++){
		if(dikunjungi[i] == false and jarak[i] <= min){ //jika node nya belum dikunjungi dan jarak dari satu node ke node lain kurang atau sama dengan nilai min maka masuk ke dalam
			//pengkonisian ini
			min = jarak[i]; //variabel min akan menampung jarak dari node satu dengan node yang lain 
			node = i; // varibel node akan menyimpan nilai dari i, dimana i merupakan node yang tersambung dengan node yang terpilih namun dengan bobot terkecil
		}
	}
	return node; //setelah dilakukan perulangan maka program akan mengembalikan nilai dari variabel node yang dimana variabel node akan berisi vertex yang berhubungan 
	//namun dengan bobot yang terkecil
}
void tampilkan_solusi(int jarak[], int par[]){
	for(int i = 0; i < vertex; i++){
		int simpan; 
		simpan = par[i];
		while(simpan != -1){
			cout << simpan << " <- "; 
			simpan = par[simpan];
		}
		cout << endl;
		cout <<"jarak minumum : " << jarak[i];
		cout << endl;
	}

}
void dijkstra(int node_pilihan){
	int par[10]; //array par akan menampung vertex mana saja yang sudah dilakukan pengunjungan atau dengan kata lain menyimpan vertex mana saja yang sudah dihubungi
	int jarak[10]; // array jarak akan menampung jarak dari setiap vertex
	bool dikunjungi[10] = {0}; // arrray dikunjungi diisi dengan nilai 0 yang  menandakan bahwa semua vertex belum pernah dikunjungi sebelumnya
	fill(jarak, jarak + vertex, INT_MAX); //menggunaakan fungsi file yang merupakan bagian dari file header bits/c++.h 
	jarak[node_pilihan] = 0; //menginisiasi jarak vertex yang dipilih terhadap dirinya sendiri adalah 0
	par[node_pilihan] = -1; // array par akan bernilai - 1 yang menandakan bahwa node pilihan sudah pernah dikunjugi
	for(int i = 1; i <= vertex; i++){
		int get_min = minimum_vertex(jarak, dikunjungi); // mencari vertex lain yang terhubung dengan vertex pilihan kemudian mencari bobot minimumnya dan kemudian hasilnya disimpan di dalam variael get_min
		dikunjungi[get_min] = true; //vertex yang telah dikunjungi akan diisi dengan nilai true
		cout <<"minimum : " << get_min << endl;  
		for(int j = 0; j < vertex; j++){
			if(!dikunjungi[j] and (jarak[get_min] + jarak_vertex[get_min][j]) < jarak[j] and jarak_vertex[get_min][j] != 9999){ //jika hasil penjumlahan jarak node sebelumya dengan jarak_vertex[get_min][j] terhadap jarak[j] 
				//jarak_vertex[get_min][j] nilai nya tidak sama dengan 9999
				par[j] = get_min; //maka node yang ditampung di dalam variabel get_min akan diatampung di dalam arrray par
				jarak[j] = jarak[get_min] + jarak_vertex[get_min][j]; // kemudian jarak menuju j akan dilakukan operasi penambahan
			}
		}
	}
	tampilkan_solusi(jarak, par); //menampilkan semua soluisi yang ada
}
int main(){
	int simpul; 
	int node_awal;
	cout <<"ketik banyak simpul yang anda inginkan : "; 
	cin >> simpul; 
	for(int i = 0; i < simpul; i++){
		for(int j = 0; j < simpul; j++){
			cout <<"ketik bobot vertex " << i << " dengan " << j << " : "; 
			cin >> jarak_vertex[i][j]; 
		}
	}
	cout <<"ketik node awal : "; 
	cin >> node_awal; 
	dijkstra(node_awal); 
	return 0;
}