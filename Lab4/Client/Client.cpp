#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

struct item
{
	char word[32];
	int pages[10];
};

int main()
{
	sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(1280);
	peer.sin_addr.s_addr = inet_addr("127.0.0.1");

	int s = socket(AF_INET, SOCK_STREAM, 0);
	connect(s, (sockaddr*)&peer, sizeof(peer));

	bool exit = false;
	int choice, o;
	char buf[sizeof(item::word)];
	item t;

	while (!exit)
	{
		cout << "1. Show all\n2. Show word\n3. Add\n4. Delete\n5. Exit\n";
		cin >> choice;
		getc(stdin);

		switch (choice)
		{
			case 1:
				send(s, "1", 2, 0);				

				while (o = recv(s, (char*)&t, sizeof(t), 0))
				{
					if (o == 1) break;

					cout << "Word: " << t.word << endl
						<< "Pages: ";

					for (int i = 0; i < sizeof(t.pages) / sizeof(t.pages[0]); i++)
					{
						if (t.pages[i] == -1) break;                        
						cout << t.pages[i] << ", ";\
					}
					cout << endl << endl;
				}
				break;
			case 2:
				send(s, "2", 2, 0);

				cout << "Enter word: ";
				cin.getline(buf, sizeof(buf), '\n');

				send(s, buf, sizeof(buf), 0);

				if (recv(s, (char*)&t.pages, sizeof(t.pages), 0) == 1)
					cout << "There's no such word";
				else
				{
					cout << "Pages: ";
					for (int i = 0; i < sizeof(t.pages) / sizeof(t.pages[0]); i++)
					{
						if (t.pages[i] == -1) break;                        
						cout << t.pages[i] << ", ";
					}
				}
				cout << endl << endl;
				break;
			case 3:
				send(s, "3", 2, 0);

				memset(t.pages, -1, sizeof(t.pages));

				cout << "Enter word: ";
				cin.getline(t.word, sizeof(t.word), '\n');
				cout << "Enter pages: ";

				for (int i = 0; i < sizeof(t.pages) / sizeof(t.pages[0]); i++)
				{                    
					cin >> t.pages[i];
					if (t.pages[i] == -1) break;    
				}
				cout << endl;

				send(s, (const char*)&t, sizeof(t), 0);

				break;
			case 4:
				send(s, "4", 2, 0);

				cout << "Enter word: ";
				cin.getline(buf, sizeof(buf), '\n');
				cout << endl;

				send(s, buf, sizeof(buf), 0);
				break;
			case 5:
				exit = true;
		}
	}

	return 0;

}