#include <stdio.h>
#include <mips.h>


// base circuit
void nand_circuit(Signal in1, Signal in2, Signal *out) {
    *out = !(in1 && in2);
}

void not_gate(Signal in, Signal *out) {
    nand_circuit(in, in, out);
}

void and_gate(Signal in1, Signal in2, Signal *out) {
    Signal mid;
    nand_circuit(in1, in2, &mid);
    not_gate(mid, out);
}

void or_gate(Signal in1, Signal in2, Signal *out) {
    Signal mid1, mid2;
    not_gate(in1, &mid1);
    not_gate(in2, &mid2);
    nand_circuit(mid1, mid2, out);
}

// not used
void nor_circuit(Signal in1, Signal in2, Signal *out) {
    Signal or_out;
    or_gate(in1, in2, &or_out);
    not_gate(or_out, out);
}



void test_gate() {
    Signal a, b, out;

    // NOT gate test
    for (a = 0; a <= 1; a++) {
        not_gate(a, &out);
        printf("NOT(%d) = %d\n", a, out);
    }

    // AND gate test
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            and_gate(a, b, &out);
            printf("AND(%d, %d) = %d\n", a, b, out);
        }
    }

    // OR gate test
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            or_gate(a, b, &out);
            printf("OR(%d, %d) = %d\n", a, b, out);
        }
    }

    // NAND circuit test
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            nand_circuit(a, b, &out);
            printf("NAND(%d, %d) = %d\n", a, b, out);
        }
    }

    // NOR circuit test
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            nor_circuit(a, b, &out);
            printf("NOR(%d, %d) = %d\n", a, b, out);
        }
    }
}