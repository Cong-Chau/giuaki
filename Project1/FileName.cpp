#include<iostream>
#include<string.h>

using namespace std;

struct Film {
	char* id;
	char* name;
	char* studio;
	int year;
	float score;
};

struct Node {
	Film data;
	Node* next;
};

void upperFirst(char x[]) {
	for (int i = 0; i < strlen(x); i++)
		if (x[i] >= 'A' && x[i] <= 'Z')
			x[i] += 32;
	x[0] -= 32;
	for (int i = 1; i < strlen(x); i++)
		if (x[i] == ' ')
			x[i + 1] -= 32;
}

bool checkID(char x[], Node* f, int n) {
	if (strlen(x) != 5)
		return false;
	for (int i = 0; i < n; i++) {
		if (strcmp(x, f->data.id) == 0)
			return false;
		f = f->next;
	}
	return true;
}

bool checkScore(float x) {
	if (x < 0 || x>10)
		return false;
	if (x > 'a' && x < 'z' || x>'A' && x < 'Z')
		return false;
	return true;
}

Node* makeNode(Film x) {
	Node* tmp = new Node;
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
void addLast(Node*& f, Film x) {
	Node* tmp = makeNode(x);
	if (f == NULL)
		f = tmp;
	else {
		Node* last = f;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = tmp;
	}
}

void inputFilm(Film& x, Node* f, int i) {
	//id
	char tmp1[10];
	cin.ignore();
	cout << "Ma so: "; 
	cin.getline(tmp1, 10);
	while (!checkID(tmp1, f, i)) {
		cout << "Ma so khong hop le hoac da ton tai\n";
		cout << "Nhap lai: "; cin.getline(tmp1, 50);
	}
	//ten
	char tmp2[50];
	cout << "Ten phim: ";
	cin.getline(tmp2, 50); upperFirst(tmp2);
	//hang phim
	char tmp3[50];
	cout << "Hang phim: ";
	cin.getline(tmp3, 50); upperFirst(tmp3);
	//nam
	cout << "Nam phat hanh: ";
	cin >> x.year;
	//danh gia
	cout << "Diem danh gia: ";
	cin >> x.score;
	while (!checkScore(x.score)) {
		cout << "Diem danh gia khong hop le, nhap lai: ";
		cin >> x.score;
	}
	
	x.id = new char[strlen(tmp1) + 1];
	strcpy_s(x.id, strlen(tmp1) + 1, tmp1);
	x.name = new char[strlen(tmp2) + 1];
	strcpy_s(x.name, strlen(tmp2) + 1, tmp2);
	x.studio = new char[strlen(tmp3) + 1];
	strcpy_s(x.studio, strlen(tmp3) + 1, tmp3);
	
}

void inputList_film(Node*& film, int n) {
	for (int i = 0; i < n; i++) {
		Film x;
		inputFilm(x, film, i);
		addLast(film, x);
		cout << endl;
	}
}

void displayList_film(Node* film) {
	while (film != NULL) {
		cout << "  " << film->data.id;
		cout << "  " << film->data.name;
		cout << "  " << film->data.studio;
		cout << "  " << film->data.year;
		cout << "  " << film->data.score;
		cout << endl;
		film = film->next;
	}
}

void phimgiongnhau(Node* film) {
	char x[50];
	cin.ignore();
	cout << "Hang phim: "; cin.getline(x, 50); upperFirst(x);
	Node* tmp1 = film;
	int dem = 0;
	while (tmp1 != NULL) {
		if ((strcmp(x, tmp1->data.studio) == 0) && (tmp1->data.score >= 6 && tmp1->data.score <= 8))
			dem++;
		tmp1 = tmp1->next;
	}
	cout << "So luong phim cung nsx: " << dem << endl;
	Node* tmp2 = film;
	while (tmp2 != NULL) {
		if ((strcmp(x, tmp2->data.studio) == 0) && (tmp2->data.score >= 6 && tmp2->data.score <= 8)) {
			cout << "  " << tmp2->data.id;
			cout << "  " << tmp2->data.name;
			cout << "  " << tmp2->data.studio;
			cout << "  " << tmp2->data.year;
			cout << "  " << tmp2->data.score;
			cout << endl;
			tmp2 = tmp2->next;
		}
	}
}

int main() {

	Node* film = NULL;
	int n;

	cout << "        ==MENU==\n";
	cout << "= 1. Nhap va xet tinh hop le\n";
	cout << "= 2. Xuat so luong va danh sach phim cung NSX\n";
	cout << "= 3. Sap xep tang dang theo MS, them 1 phim sao cho duy tri thu tu\n";
	int chon; cout << "\nChon muc ban muon kiem tra: "; cin >> chon;
	while (chon < 1 && chon>3) {
		cout << "Chon khong hop le, chon lai: "; cin >> chon;
	}
	switch (chon) {
	case 1: {
		cout << "So luong: ";
		cin >> n;
		inputList_film(film, n);
		displayList_film(film);
		break;
	}
	case 2: {
		cout << "Phai nhap danh sach truoc\n";
		cout << "So luong: ";
		cin >> n;
		inputList_film(film, n);
		phimgiongnhau(film);
		break;
	}
	case 3: {
		cout << "Phai nhap danh sach truoc\n";
		cout << "So luong: ";
		cin >> n;
		inputList_film(film, n);

		cout << "chua lam\n";
		break;
	}

	}

	cout << "Ban co muon kiem tra tiep hay khong?\n";
	cout << " 1. Co\t2. Khong\n";
	int a; cout << "Chon: "; cin >> a;
	while (a != 1 && a != 2) {
		cout << "Chon khong hop le, chon lai: ";
		cin >> a;
	}


	while (a == 1) {
		cout << "\nBan co muon nhap lai danh sach khong?\n";
		cout << " 1. Co\t2. Khong\n";
		int b; cout << "Chon: "; cin >> b;
		if (b == 1) {
			cout << "n = "; cin >> n;
			///
		}

		cout << "        ==MENU==\n";
		cout << "= 0. Thoat!\n";
	//	cout << "= 1. Nhap va xet tinh hop le\n";
		cout << "= 2. Xuat so luong va danh sach phim cung NSX\n";
		cout << "= 3. Sap xep tang dang theo MS, them 1 phim sao cho duy tri thu tu\n";

		int chon; cout << "\nChon muc ban muon kiem tra: "; cin >> chon;
		while (chon < 1 && chon>3) {
			cout << "Chon khong hop le, chon lai: "; cin >> chon;
		}
		if (chon == 0) {
			cout << "Ket thuc chuong trinh.\n";
			break;
		}
		switch (chon) {
		
		case 2: {
			cout << "Phai nhap danh sach truoc\n";
			cout << "So luong: ";
			cin >> n;
			inputList_film(film, n);
			phimgiongnhau(film);
			break;
		}
		case 3: {
			cout << "chua lam " <<  endl;
			break;
		}

		}

		cout << "Ban co muon tiep tuc kiem tra khong?\n";
		cout << " 1. Co\t2. Khong\n";
		int c; cout << "Chon: "; cin >> c;
		if (c == 2)
			break;
	}

	system("pause");
	return 0;
}