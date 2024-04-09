int nodes, edges;
    fin >> nodes >> edges;

    Graph graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int first_node, second_node;
        fin >> first_node >> second_node;
        graph.addEdge(first_node, second_node);
    }

    fin.close();

    int src;
    std::cout << "Enter the src: ";
    std::cin >> src;

    graph.moore(src);