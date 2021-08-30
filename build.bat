em++ --bind .\cpp\bindings\GorgonBindings.cpp -Icpp ^
.\cpp\MatchManager.cpp ^
.\cpp\Match.cpp ^
.\cpp\board\Board.cpp ^
.\cpp\board\BoardData.cpp ^
.\cpp\board\RulesValidator.cpp ^
.\cpp\board\Snake.cpp ^
-s WASM=1 -s MODULARIZE=1 -o .\js\wasm_generated\Gorgon.js