enum bloco_estado {
	livre,
	parede,
	queijo,
	visitado,
	desconhecido,
};

typedef struct bloco {
	int x, y;

	enum bloco_estado estado;

	struct bloco *cima,
		 *direita,
		 *baixo,
		 *esquerda;
} bloco;
