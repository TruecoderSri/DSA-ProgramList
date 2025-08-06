bool notvisited(vector<vector<int>> &visited, int row, int col)
{

    if (visited[row][col] == 0)
    {

        return true;
    }

    else
    {

        return false;
    }
}

bool isOpen(vector<vector<int>> &m, int n, int row, int col)

{

    if ((0 <= row && row < n) && (0 <= col && col < n) && (m[row][col] == 1))
    {

        return true;
    }

    else
    {

        return false;
    }
}

void findway(vector<vector<int>> &m, vector<vector<int>> &visited, int n,

             int row, int col, string path, vector<string> &paths)

{

    if (row == n - 1 && col == n - 1)
    {

        paths.push_back(path);

        return;
    }

    // down.

    int nextrow = row + 1, nextcol = col;

    if (isOpen(m, n, nextrow, nextcol) && notvisited(visited, nextrow, nextcol))
    {

        visited[row][col] = 1;

        path.push_back('D');

        findway(m, visited, n, nextrow, nextcol, path, paths);

        // backtrack.

        path.pop_back();

        visited[row][col] = 0;
    }

    // Right.

    nextrow = row, nextcol = col + 1;

    if (isOpen(m, n, nextrow, nextcol) && notvisited(visited, nextrow, nextcol))
    {

        visited[row][col] = 1;

        path.push_back('R');

        findway(m, visited, n, nextrow, nextcol, path, paths);

        path.pop_back();

        visited[row][col] = 0;
    }

    // left

    nextrow = row, nextcol = col - 1;

    if (isOpen(m, n, nextrow, nextcol) && notvisited(visited, nextrow, nextcol))
    {

        visited[row][col] = 1;

        path.push_back('L');

        findway(m, visited, n, nextrow, nextcol, path, paths);

        path.pop_back();

        visited[row][col] = 0;
    }

    // up.

    nextrow = row - 1, nextcol = col;

    if (isOpen(m, n, nextrow, nextcol) && notvisited(visited, nextrow, nextcol))
    {

        visited[row][col] = 1;

        path.push_back('U');

        findway(m, visited, n, nextrow, nextcol, path, paths);

        path.pop_back();

        visited[row][col] = 0;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{

    vector<string> paths;

    if (m[0][0] == 0)

        return paths;

    int row = 0, col = 0;

    vector<vector<int>> visited = m;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            visited[i][j] = 0;
        }
    }

    string path;

    findway(m, visited, n, row, col, path, paths);

    sort(paths.begin(), paths.end());

    return paths;
}
}
;