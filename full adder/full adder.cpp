#include <systemc.h>
using namespace std;

SC_MODULE(FULL_ADDER) {
	sc_in<bool> A;
	sc_in<bool> B;
	sc_in<bool> Cin;
	sc_out<bool> sum;
	sc_out<bool> carry;

	SC_CTOR(FULL_ADDER) {
		SC_METHOD(full_adder_logic);
		sensitive << A << B << Cin;
	}

	void full_adder_logic(void) {
		sum.write(A.read() ^ B.read() ^ Cin.read());
		carry.write((A.read() && B.read()) || (Cin.read() && (A.read() ^ B.read())));

	}
};

int sc_main(int, char* []) {
	sc_signal <bool> signal_A, signal_B, signal_Cin, SUM, CARRY;
	FULL_ADDER full_adder("Fulladder");
	full_adder.A(signal_A);
	full_adder.B(signal_B);
	full_adder.Cin(signal_Cin);
	full_adder.sum(SUM);
	full_adder.carry(CARRY);

	signal_A = false;
	signal_B = false;
	signal_Cin = false;

	sc_start(1, SC_NS);

	cout << "when A=0,B=0 and Cin=0 sum = " << SUM.read() << "and carry =" << CARRY.read() << endl;

	signal_A = false;
	signal_B = false;
	signal_Cin = true;

	sc_start(1, SC_NS);

	cout << "when A=0,B=0 and Cin=1 sum = " << SUM.read() << "and carry =" << CARRY.read() << endl;

	signal_A = false;
	signal_B = true;
	signal_Cin = false;

	sc_start(1, SC_NS);

	cout << "when A=0,B=1 and Cin=0 sum = " << SUM.read() << "and carry =" << CARRY.read() << endl;


	signal_A = false;
	signal_B = true;
	signal_Cin = true;

	sc_start(1, SC_NS);

	cout << "when A=0,B=1 and Cin=1 sum = " << SUM.read() << "and carry =" << CARRY.read() << endl;

	signal_A = true;
	signal_B = false;
	signal_Cin = false;

	sc_start(1, SC_NS);

	cout << "when A=1,B=0 and Cin=0 sum = " << SUM.read() << "and carry =" << CARRY.read() << endl;

	signal_A = true;
	signal_B = false;
	signal_Cin = true;

	sc_start(1, SC_NS);

	cout << "when A=1,B=0 and Cin=1 sum = " << SUM.read() << "and carry =" << CARRY.read() << endl;

	signal_A = true;
	signal_B = true;
	signal_Cin = false;

	sc_start(1, SC_NS);

	cout << "when A=1,B=1 and Cin=0 sum = " << SUM.read() << "and carry =" << CARRY.read() << endl;

	signal_A = true;
	signal_B = true;
	signal_Cin = true;

	sc_start(1, SC_NS);

	cout << "when A=0,B=0 and Cin=0 sum = " << SUM.read() << "and carry =" << CARRY.read() << endl;
	return 0;
}
