import sympy as sp

# Define symbols
s, z = sp.symbols('s z')

# Given transfer function
Ha_BP_s = 6.49e-5 * s**4 / (s**8 + 0.144*s**7 + 0.1682*s**6 + 0.1810*s**5 + 1.05*s**4 + 0.750*s**3 + 0.289*s**2 + 0.0102*s + 0.029)

# Perform substitution
substitution = ((1 - z**-1) / (1 + z**-1))
substituted_expression = Ha_BP_s.subs(s, substitution)

# Simplify the expression
simplified_expression = sp.simplify(substituted_expression)

# Print the result
print("Expression in z:")
print(simplified_expression)


