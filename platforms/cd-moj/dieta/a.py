# M = Limite de calorias
# N = Número de refeições
N, M = map(int, input().split())

refeicoes_dentro_do_limite = 0

for _ in range(N):
    p, g, c = map(int, input().split())
    print(g, g, c)
    
    # Cálculo das calorias (Proteína: 4, Gordura: 9, Carboidrato: 4)
    total_calorias = (p * 4) + (g * 9) + (c * 4)
    
    if total_calorias <= M:
        refeicoes_dentro_do_limite += 1

print(refeicoes_dentro_do_limite)
