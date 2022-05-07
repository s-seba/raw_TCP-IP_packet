#include "functions.h"

int main(int argc, char** argv) {

	if (argc < 7) {
		info();
		exit(1);
	}

	std::vector<std::string> ip_header{};
	std::vector<std::string> tcp_header{};

	set_ip_header(ip_header, argv[1], argv[2], argv[3]);
	set_tcp_header(tcp_header, argv[4], argv[5], argv[6]);
	calc_ip_checksum(ip_header);
	calc_tcp_checksum(ip_header, tcp_header);
	auto packet = create_packet(ip_header, tcp_header);

	std::cout << packet << '\n' << argv[2];

	auto test = "4500 0028 abcd 0000 4006 c33d c0a8 8991 c0a8 00e3 3039 0050 0000 0000 0000 0000 5002 7110 0284 0000";

	if (test == packet) {
		std::cout << "\nOK";
	}
	else {
		std::cout << "\nWRONG!";
	}

	return 0;

}