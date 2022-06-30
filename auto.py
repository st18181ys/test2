from automata.fa.dfa import DFA

dfa = DFA(
    states={'q0', 'q1', 'q2'},
    input_symbols={'0', '1'},
    transitions={
        'q0': {'0': 'q0', '1': 'q1'},
        'q1': {'0': 'q0', '1': 'q2'},
        'q2': {'0': 'q2', '1': 'q1'}
    },
    initial_state='q0',
    final_states={'q1'}
)

r = dfa.read_input('01')
print(f"read_input: {r}")

if dfa.accepts_input("01101"):
    print('accepted')
else:
    print('rejected')

r = dfa.read_input_stepwise('0111')
for i in r:
    print(f"{i}")