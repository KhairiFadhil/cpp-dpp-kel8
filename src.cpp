#include <iostream>
#include <vector>

using namespace std;

struct Account {
	string username;
	string password;
};

bool logout() {
	return false;
}


bool login(string username, string password, const vector<Account>& accounts) {
	for (const Account& account : accounts) {

		if (username == account.username && password == account.password) {
			cout << "Login Berhasil!, Selamat datang " << username << endl;
			return true;
		}
	}
	cout << "Username/Password Salah" << endl;
	return false;
}

void registerAccount(string username, string password, vector<Account>& verif) {
	for (const Account& account : verif) {
		if (username == account.username) {
			cout << "Registrasi Gagal, Akun sudah terdaftar." << endl;
			return;
		}
	}

	verif.push_back({username, password});
	cout << "Registration successful!" << endl;
}

int main() {
	vector<Account> accounts = {{"admin", "admin123"}};
	vector<Account> verif = {};
	string username, password;
	string regUsername, regPassword;
	bool isLogged = false;
	int n;

	while (true) {
		cout << "========== KeKasir ==========" << endl;
		cout << "1. Register" << endl << "2. Login" << endl << "3. Exit" << endl;
		cin >> n;

		if (n == 1) {
			cout << "==Register==" << endl << "Username: ";
			cin >> regUsername;
			cout << "Password: ";
			cin >> regPassword;
			registerAccount(regUsername, regPassword, verif);
		} else if (n == 2) {
			while (!isLogged) {
				cout << "Username: ";
				cin >> username;
				cout << "Password: ";
				cin >> password;
				isLogged = login(username, password, accounts);
			}
		} else if (n == 3) {
			cout << "Exiting the program. Goodbye!" << endl;
			break;
		} else {
			cout << "Invalid option. Please try again." << endl;
		}


		while (isLogged) {
		    while(true){
			int input;
			cout << "========================================" << endl;
			cout << "User: " << username << endl;
			cout << "9: Log Out" << endl;
			cout << "8. Account Approval";
			if(verif.size()  > 0) {
				cout << endl;
				cout << "(Terdapat "<< verif.size() << " " << "akun menunggu Verifikasi)" << endl;
			} else {
				cout << endl;
			}
			cout << "========================================" << endl;
			cout << "1.Kasir" << endl;
			cout << "2.Inventaris" << endl;
				cin >> input;
			if(input == 1) {
				
   int Jumlah_uang=0, Total_harga=0, Kembalian=0;
   int pulpen=0, pensil=0, penggaris=0, penghapus=0, input1,input2;
   while(true){
    if(pulpen > 0){
        cout << "Pulpen : " << pulpen << endl;
    }
    if(pensil > 0){
        cout << "Pensil : " << pensil << endl;
    }if(penggaris > 0){
        cout << "Penggaris: " << penggaris << endl;
    }if(penghapus > 0){
        cout << "Penghapus : " << penghapus << endl;
    }
    
    cout << "Masukkan barang yang dibeli " << endl;
    cout << "1 . Pulpen" << endl << "2 . Pensil" << endl << "3 . Penggaris" << endl << "4 . Penghapus" << endl << "9   .   Close" << endl;
    cin >> input1;
    cout << "Masukkan jumlah barang yang dibeli ";
        if(input1 == 1){
            cin >> input2;
            pulpen  += input2;
            cout << "Pulpen : " << pulpen <<endl;
        }else if(input1 == 2){
            cin >> input2;
            pensil += input2;
            cout << "Pensil : " << pensil <<endl;
        }else if(input1 == 3){
            cin >> input2;
            penggaris += input2;
            cout << "Penggaris :  " << penggaris <<endl;
        }else if(input1 == 4){
            cin >> input2;
            penghapus += input2;
            cout << "Penghapus : " << penghapus << endl;
        }
        else if(input1 == 9){
            break;
        }
   }
    int harga_pulpen = 3000 * pulpen;
    int harga_pensil = 1000 * pensil;
    int harga_penggaris = 3000 * penggaris;
    int harga_penghapus = 1500 * penghapus;
    
   Total_harga = harga_pulpen + harga_pensil + harga_penggaris + harga_penghapus;
   int lanjut;
   cout << "Total harga : ";
   cout << Total_harga <<endl;
    cout << "Masukkan nominal uang yang diberikan : ";
    cin >> Jumlah_uang;
    cout << endl;
    if(Jumlah_uang > Total_harga){
         Kembalian = Jumlah_uang - Total_harga;
         cout << "Kembalian : " << Kembalian << endl;
    }else{
        cout << "Duid kurang euy..";
    }
    cout << "Ketik apapun untuk lanjut";
    cin >> lanjut;
			}
			if(input == 2) {
			    int pulpen = 0, pensil = 0, penggaris = 0;
				while (true) {
			
					int input1, input2;
					cout << "Barang Apa yang Ingin Anda Tambah? " << endl;
					cout << "1. Pulpen = "<< pulpen << endl << "2. Pensil = " << pensil << endl << "3. Penggaris = " << penggaris << endl << "9. Cancel" << endl;
					cin >> input1;

					if(input1 == 1) {
						cout << "Pulpen\n" << endl;
						cout << "Berapa Jumlah Stok yang Akan ditambah? " << endl;
						cin >> input2;
						pulpen = pulpen+input2;
						cout << "Total Pulpen Adalah : " << pulpen << endl << endl;

					} else if(input1 == 2) {
						cout << "Pensil\n" << endl;
						cout << "Berapa Jumlah Stok yang Akan ditambah? " << endl;
						cin >> input2;
						pensil = pensil+input2;
						cout << "Total Pensil Adalah : " << pensil << endl << endl;

					} else if(input1 == 3) {
						cout << "Penggaris\n" << endl;
						cout << "Berapa Jumlah Stok yang Akan ditambah? " << endl;
						cin >> input2;
						penggaris = penggaris + input2;
						cout << "Total Penggaris Adalah : \n" << penggaris << endl;

					}else if(input1 == 9){
					    break;
					}
				}
			}
    		if(input == 8) {
    			int acc;
    			vector<Account>temp = {};
    			char yesno;
    			cout << "=========" << "Account Approval" << " =========" << endl << endl;
    			for (int i = 0; i < verif.size(); i++) {
    				cout << i + 1 << ". " << "Username: " << verif[i].username <<  ", Password: " << verif[i].password << endl;
    			}
    			cin >> acc;
    			char con;
    			for (int i = 0; i < verif.size(); i++) {
    				if(i == acc) {
    					cout << "Apakah kau yakin ingin menambahkan user:" << verif[i].username << "? [y/n]" << endl;
    					cin >> con;
    					if(con == 'y') {
    						accounts.push_back({verif[i].username, verif[i].password});
    						break;
    					} else {
    						break;
    					}
    				}
    			}
    		}
    		if (input == 9) {
    			char confirm;
    			cout << "Apa kau yakin ingin Logout? (y/n): ";
    			cin >> confirm;
    			if (confirm == 'y') {
    				isLogged = logout();
    			}
    }
        }
		}
}

return 0;
}
