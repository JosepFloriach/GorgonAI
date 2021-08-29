import MatchManager from './wasm_generated/Gorgon.js';
import MatchManagerWASM from './wasm_generated/Gorgon.wasm';


const gorgon = MatchManager({
	locateFile: () => {
		return MatchManagerWASM;
	},
});

class gorgon_handler
{  
	constructor(app_ref)
	{
		this.app = app_ref;
		this.board_id = 0;
	}

	create_board(size)
	{
		console.debug("Trying to create board...");
		var self = this;
		gorgon.then((match_manager) => 
		{
			
			self.board_id = match_manager.create_match();
			console.info("Board created with id " + self.board_id);
			var board_state = match_manager.resize_board(self.board_id, size);
			console.info("Board initialized with size " + size);
			self.app.setState(
			{
				board_size: size,
				board_matrix: board_state
			})
		});
	}

	on_board_size_changed(size)
	{
		var self = this;
		console.debug("Trying to change board size...");
		gorgon.then((match_manager) => 
		{
			var board_state = match_manager.resize_board(self.board_id, size);
			console.info("New board size is " + size);		
			self.app.setState(
			{
				board_size: size,
				board_matrix: board_state
			})
   		});
	}

	on_cell_click(event)
	{
		var self = this;
		var cell = event.currentTarget;
		var row = Number(cell.getAttribute('row'));
		var col = Number(cell.getAttribute('col'));
		gorgon.then((match_manager) => 
		{
			var board_state = self.app.state.current_stone_color == 1? match_manager.play_black_stone(self.board_id, row, col): match_manager.play_white_stone(self.board_id, row, col);
			console.info("Stone placed at row " + row + " and col " + col);
			console.debug(board_state);
			self.app.setState(
			{
				board_matrix: board_state
			})
		});
	}

	on_build_mode_color_changed(is_white)
	{
		var self = this;
		self.app.setState({current_stone_color: is_white == true? 1 : 2});
	}

	on_build_mode_changed()
	{	  	
		var self = this;
		self.app.setState({build_mode: !self.app.state.build_mode});
	}  

	on_ai_mode_changed(ai_mode_enabled)
	{
		var self = this;
		self.app.setState({ai_mode: ai_mode_enabled});
	}

	on_ai_algorithm_changed(algorithm)
	{
	  	console.log("TEST SUCCESS!! NEW ALGORITHM " + algorithm);
	}
		
	on_tsumego_preset_changed(tsumego_name)
	{
	  	console.log("TEST SUCCESS!! TSUMEGO " + tsumego_name);  
	}
}

export default gorgon_handler;