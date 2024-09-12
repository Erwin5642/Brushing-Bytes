class FAtoRE:
    def __init__(self, states, alphabet, transitions, start_state, accept_states):
        self.states = states
        self.alphabet = alphabet
        self.transitions = transitions  # Dictionary: {(state, symbol): {dest_state}}
        self.start_state = start_state
        self.accept_states = accept_states
    
    def get_regex(self):
        # Convert the FA into a table of transitions where each entry is a regular expression
        re_table = { (src, dest): "" for src in self.states for dest in self.states }
        
        for (src, symbol), dests in self.transitions.items():
            for dest in dests:
                if re_table[(src, dest)]:
                    re_table[(src, dest)] += f"|{symbol}"  # Union of existing and new transitions
                else:
                    re_table[(src, dest)] = symbol

        # Eliminate states one by one except start and accepting states
        for state in self.states:
            if state == self.start_state or state in self.accept_states:
                continue
            self._eliminate_state(re_table, state)
        
        # After elimination, combine transitions from start to accept states
        regex = self._final_regex(re_table)
        return regex

    def _eliminate_state(self, re_table, state):
        # Get incoming and outgoing transitions for the state to be eliminated
        incoming = [src for src in self.states if re_table[(src, state)]]
        outgoing = [dest for dest in self.states if re_table[(state, dest)]]
        loop = re_table[(state, state)]  # Self-loop (if exists)

        for src in incoming:
            for dest in outgoing:
                # Create the new transition regular expression
                new_expr = re_table[(src, state)]
                if loop:
                    new_expr += f"({loop})*"
                new_expr += re_table[(state, dest)]

                if re_table[(src, dest)]:
                    re_table[(src, dest)] += f"|{new_expr}"  # Combine transitions with OR
                else:
                    re_table[(src, dest)] = new_expr

        # Remove all transitions involving the eliminated state
        for s in self.states:
            re_table[(s, state)] = ""
            re_table[(state, s)] = ""

    def _final_regex(self, re_table):
        # Combine all transitions from the start state to each accept state
        regex = ""
        for accept_state in self.accept_states:
            if re_table[(self.start_state, accept_state)]:
                if regex:
                    regex += "|"
                regex += re_table[(self.start_state, accept_state)]
        return regex


# Example usage:
states = {'q0', 'q1', 'q2'}
alphabet = {'a', 'b'}
transitions = {
    ('q0', 'a'): {'q1'},
    ('q1', 'b'): {'q2'},
    ('q2', 'a'): {'q1'},
    ('q2', 'b'): {'q2'}
}
start_state = 'q0'
accept_states = {'q2'}

fa_to_re = FAtoRE(states, alphabet, transitions, start_state, accept_states)
regex = fa_to_re.get_regex()
print("Regular Expression:", regex)