#include "../src/Algoritmos.h"
#include "../src/Grafo.h"
#include "../../problema1/src/Edge.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;


TEST(TestGrafo, TestConstructorVacio)
{
	Grafo g;

	EXPECT_EQ(g.getCantAristas(), 0);
	EXPECT_EQ(g.getCantVertices(), 0);
}


TEST(TestGrafo, TestConstructorConParametro)
{
	std::vector<Edge> v;

	v.push_back(Edge(0, 1, 4));
	v.push_back(Edge(1, 0, 4));

	Grafo g(v, 2);

	EXPECT_EQ(g.getCantAristas(), 2);
	EXPECT_EQ(g.getCantVertices(), 2);
	EXPECT_EQ(g.getCostoArista(0, 1), 4);
	EXPECT_EQ(g.getCostoArista(1, 0), 4);
	EXPECT_EQ(g.getCostoArista(1, 1), 0);
	EXPECT_EQ(g.getCostoArista(0, 0), 0);
}


TEST(TestAlgoritmos, TestDijkstraGrafoCompleto)
{
	std::vector<Edge> v;

	v.push_back(Edge(0, 1, 4));
	v.push_back(Edge(1, 0, 1));
	v.push_back(Edge(1, 2, 3));
	v.push_back(Edge(2, 1, 25));
	v.push_back(Edge(2, 0, 1));
	v.push_back(Edge(0, 2, 25));

	Grafo g(v, 3);

	std::vector<std::vector<int>> res(3);

	res[0].resize(3, std::numeric_limits<int>::max());
	res[1].resize(3, std::numeric_limits<int>::max());
	res[2].resize(3, std::numeric_limits<int>::max());

	Dijkstra(res, g);

	EXPECT_EQ(res[0][0], 0);
	EXPECT_EQ(res[0][1], 4);
	EXPECT_EQ(res[0][2], 7);

	EXPECT_EQ(res[1][0], 1);
	EXPECT_EQ(res[1][1], 0);
	EXPECT_EQ(res[1][2], 3);
	
	EXPECT_EQ(res[2][0], 1);
	EXPECT_EQ(res[2][1], 5);
	EXPECT_EQ(res[2][2], 0);
}


TEST(TestAlgoritmos, TestDijkstraGrafoNoConexo)
{
	std::vector<Edge> v;

	v.push_back(Edge(0, 1, 4));
	v.push_back(Edge(1, 0, 1));

	Grafo g(v, 3);

	std::vector<std::vector<int>> res(3);

	int max_int = std::numeric_limits<int>::max();

	res[0].resize(3, max_int);
	res[1].resize(3, max_int);
	res[2].resize(3, max_int);

	Dijkstra(res, g);

	EXPECT_EQ(res[0][0], 0);
	EXPECT_EQ(res[0][1], 4);
	EXPECT_EQ(res[0][2], max_int);

	EXPECT_EQ(res[1][0], 1);
	EXPECT_EQ(res[1][1], 0);
	EXPECT_EQ(res[1][2], max_int);
	
	EXPECT_EQ(res[2][0], max_int);
	EXPECT_EQ(res[2][1], max_int);
	EXPECT_EQ(res[2][2], 0);
}


TEST(TestAlgoritmos, TestDijkstraGrafoSinEjes)
{
	std::vector<Edge> v;

	Grafo g(v, 5);

	std::vector<std::vector<int>> res(5);

	int max_int = std::numeric_limits<int>::max();

	res[0].resize(5, max_int);
	res[1].resize(5, max_int);
	res[2].resize(5, max_int);
	res[3].resize(5, max_int);
	res[4].resize(5, max_int);

	Dijkstra(res, g);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i == j)
			{
				EXPECT_EQ(res[i][i], 0);
			}
			else
			{
				EXPECT_EQ(res[i][j], max_int);
			}
		}
	}
}


TEST(TestAlgoritmos, TestDijkstraPQGrafoCompleto)
{
	std::vector<Edge> v;

	v.push_back(Edge(0, 1, 4));
	v.push_back(Edge(1, 0, 1));
	v.push_back(Edge(1, 2, 3));
	v.push_back(Edge(2, 1, 25));
	v.push_back(Edge(2, 0, 1));
	v.push_back(Edge(0, 2, 25));

	Grafo g(v, 3);

	std::vector<std::vector<int>> res(3);

	res[0].resize(3, std::numeric_limits<int>::max());
	res[1].resize(3, std::numeric_limits<int>::max());
	res[2].resize(3, std::numeric_limits<int>::max());

	DijkstraPQ(res, g);

	EXPECT_EQ(res[0][0], 0);
	EXPECT_EQ(res[0][1], 4);
	EXPECT_EQ(res[0][2], 7);

	EXPECT_EQ(res[1][0], 1);
	EXPECT_EQ(res[1][1], 0);
	EXPECT_EQ(res[1][2], 3);
	
	EXPECT_EQ(res[2][0], 1);
	EXPECT_EQ(res[2][1], 5);
	EXPECT_EQ(res[2][2], 0);
}


TEST(TestAlgoritmos, TestDijkstraPQGrafoNoConexo)
{
	std::vector<Edge> v;

	v.push_back(Edge(0, 1, 4));
	v.push_back(Edge(1, 0, 1));

	Grafo g(v, 3);

	std::vector<std::vector<int>> res(3);

	int max_int = std::numeric_limits<int>::max();

	res[0].resize(3, max_int);
	res[1].resize(3, max_int);
	res[2].resize(3, max_int);

	DijkstraPQ(res, g);

	EXPECT_EQ(res[0][0], 0);
	EXPECT_EQ(res[0][1], 4);
	EXPECT_EQ(res[0][2], max_int);

	EXPECT_EQ(res[1][0], 1);
	EXPECT_EQ(res[1][1], 0);
	EXPECT_EQ(res[1][2], max_int);
	
	EXPECT_EQ(res[2][0], max_int);
	EXPECT_EQ(res[2][1], max_int);
	EXPECT_EQ(res[2][2], 0);
}


TEST(TestAlgoritmos, TestDijkstraPQGrafoSinEjes)
{
	std::vector<Edge> v;

	Grafo g(v, 5);

	std::vector<std::vector<int>> res(5);

	int max_int = std::numeric_limits<int>::max();

	res[0].resize(5, max_int);
	res[1].resize(5, max_int);
	res[2].resize(5, max_int);
	res[3].resize(5, max_int);
	res[4].resize(5, max_int);

	DijkstraPQ(res, g);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i == j)
			{
				EXPECT_EQ(res[i][i], 0);
			}
			else
			{
				EXPECT_EQ(res[i][j], max_int);
			}
		}
	}
}


TEST(TestAlgoritmos, TestFloydGrafoCompleto)
{
	std::vector<Edge> v;

	v.push_back(Edge(0, 1, 4));
	v.push_back(Edge(1, 0, 1));
	v.push_back(Edge(1, 2, 3));
	v.push_back(Edge(2, 1, 25));
	v.push_back(Edge(2, 0, 1));
	v.push_back(Edge(0, 2, 25));

	Grafo g(v, 3);

	std::vector<std::vector<int>> res(3);

	res[0].resize(3, std::numeric_limits<int>::max());
	res[1].resize(3, std::numeric_limits<int>::max());
	res[2].resize(3, std::numeric_limits<int>::max());

	FloydWarshall(res, g);

	EXPECT_EQ(res[0][0], 0);
	EXPECT_EQ(res[0][1], 4);
	EXPECT_EQ(res[0][2], 7);

	EXPECT_EQ(res[1][0], 1);
	EXPECT_EQ(res[1][1], 0);
	EXPECT_EQ(res[1][2], 3);
	
	EXPECT_EQ(res[2][0], 1);
	EXPECT_EQ(res[2][1], 5);
	EXPECT_EQ(res[2][2], 0);
}


TEST(TestAlgoritmos, TestFloydGrafoNoConexo)
{
	std::vector<Edge> v;

	v.push_back(Edge(0, 1, 4));
	v.push_back(Edge(1, 0, 1));

	Grafo g(v, 3);

	std::vector<std::vector<int>> res(3);

	int max_int = std::numeric_limits<int>::max();

	res[0].resize(3, max_int);
	res[1].resize(3, max_int);
	res[2].resize(3, max_int);

	FloydWarshall(res, g);

	EXPECT_EQ(res[0][0], 0);
	EXPECT_EQ(res[0][1], 4);
	EXPECT_EQ(res[0][2], max_int);

	EXPECT_EQ(res[1][0], 1);
	EXPECT_EQ(res[1][1], 0);
	EXPECT_EQ(res[1][2], max_int);
	
	EXPECT_EQ(res[2][0], max_int);
	EXPECT_EQ(res[2][1], max_int);
	EXPECT_EQ(res[2][2], 0);
}


TEST(TestAlgoritmos, TestFloydGrafoSinEjes)
{
	std::vector<Edge> v;

	Grafo g(v, 5);

	std::vector<std::vector<int>> res(5);

	int max_int = std::numeric_limits<int>::max();

	res[0].resize(5, max_int);
	res[1].resize(5, max_int);
	res[2].resize(5, max_int);
	res[3].resize(5, max_int);
	res[4].resize(5, max_int);

	FloydWarshall(res, g);
	
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i == j)
			{
				EXPECT_EQ(res[i][i], 0);
			}
			else
			{
				EXPECT_EQ(res[i][j], max_int);
			}
		}
	}
}
