/*
 * This file is part of Connect4 Game Solver <http://connect4.gamesolver.org>
 * Copyright (C) 2017-2019 Pascal Pons <contact@gamesolver.org>
 *
 * Connect4 Game Solver is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * Connect4 Game Solver is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with Connect4 Game Solver. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Solver.hpp"

using namespace GameSolver::Connect4;

static Solver solver;

extern "C"
{

void
LoadSolver (void)
{
  solver.loadBook ("Connect4OpeningBook.bin");
}

int
GetMoveScore (const char *moveSeq, int column)
{
  Position P;
  std::string realMoveSeq (moveSeq);
  if (P.play (realMoveSeq) != realMoveSeq.size ())
    return -1;
  P.playCol (column);
  return solver.solve (P, false);
}

}
