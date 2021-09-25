# Graph-Theory

### Students
 - Natália de Assis Sousa
 - João Vitor Santos Tavares

### Implemented Algorithms

- Prim Algorithm
- Ford-Fulkerson Algorithm
- Dijkstra Algorithm
- Kruskal Algorithm

Each of the implemented algorithms has its input
code and .cpp in the name directory located in the algs directory.

### Prim Algorithm

### Ford-Fulkerson Algorithm

To run this algorithm first compile the ford-fulkerson.cpp file

``` 
g++ -o ford-fulkerson ford-fulkerson.cpp
```

Then run the command

```
./ford-fulkerson (arquivo de entrada)
```

Here is a demonstration of the result of running this algorithm:

![](https://github.com/JT4v4res/Graph-Theory/blob/main/imgs/ford-fulkerson.png)

This was the input used for testing:

```
6 8
1 2 5
1 3 4
1 4 2
1 6 6
2 4 1
2 5 7
3 5 6
4 6 1
```

### Dijkstra Algorithm

To run this algorithm first compile the ford-fulkerson.cpp file

``` 
g++ -o dijkstra dijkstra.cpp
```

Then run the command

```
./dijkstra < in
```

Here is a demonstration of the result of running this algorithm:

![](https://github.com/JT4v4res/Graph-Theory/blob/main/imgs/dijkstra.png)

This was the input used for testing:

```
6 8
1 2 5
1 3 4
1 4 2
1 6 6
2 4 1
2 5 7
3 5 6
4 6 1
```

### Kruskal Algorithm

To run this algorithm first compile the ford-fulkerson.cpp file

``` 
g++ -o kruskal kruskal.cpp
```

Then run the command

```
./kruskal < in
```

Here is a demonstration of the result of running this algorithm:

![](https://github.com/JT4v4res/Graph-Theory/blob/main/imgs/kruskal.png)

This was the input used for testing:

```
8 16
0 2 4
0 3 6
0 4 2
1 5 3
1 6 3
2 0 4
3 0 6
3 5 1
4 0 2
4 6 6
4 7 8
5 1 3
5 3 1
6 1 3
6 4 6
7 4 8
```

See you next time!
<br><br>

![](https://media.giphy.com/media/d1xWB9Oy1ebPq/giphy.gif?cid=790b76111ce5b954ac61502acc9c76ed7551d126e0a61ebb&rid=giphy.gif&ct=g)