import React from 'react';
import chunk from 'lodash/chunk';
import { Row, Col } from 'antd';

import '../../css/goboard.css'

var asset_top_left = "assets/top_left.png";
var asset_top_right = "assets/top_right.png";
var asset_bottom_left = "assets/bottom_left.png";
var asset_bottom_right = "assets/bottom_right.png";
var asset_border_top = "assets/border_top.png";
var asset_border_left =  "assets/border_left.png";
var asset_border_right =  "assets/border_right.png"
var asset_border_bottom =  "assets/border_bottom.png"
var asset_common_intersection = "assets/common_intersection.png";
var asset_white_stone = "assets/white_stone.png";
var asset_black_stone = "assets/black_stone.png";

class GoBoard extends React.Component
{
	componentWillReceiveProps(nextProps) 
	{
		this.setState( 
		{
			board_size : nextProps.board_size,
			ai_mode : nextProps.ai_mode,
			current_stone_color : nextProps.current_stone_color,
			board_matrix: nextProps.board_matrix
		});
  	}

	onCellEnter(event)
	{
		var cell = event.currentTarget;
		if (this.state.current_stone_color == 2)
		{
			cell.querySelector(".black_stone_hint").style.visibility = "visible";
			cell.querySelector(".white_stone_hint").style.visibility = "hidden";
		}
		else
		{
			cell.querySelector(".white_stone_hint").style.visibility = "visible";
			cell.querySelector(".black_stone_hint").style.visibility = "hidden";
		}	
	}

	onCellLeave(event)
	{
		var cell = event.currentTarget;
		cell.querySelector(".black_stone_hint").style.visibility = "hidden";
		cell.querySelector(".white_stone_hint").style.visibility = "hidden";
	}

	get_intersection_asset(row, col)
	{
		var boardSize = this.props.board_size;
		if (row == 0 && col == 0)
		{
			return asset_top_left;
		}
		if (row == 0 && col == boardSize - 1)
		{
			return asset_top_right;
		}
		if (row == boardSize -1 && col == 0)
		{
			return asset_bottom_left;
		}
		if (row == boardSize -1 && col == boardSize -1)
		{
			return asset_bottom_right;	
		}
		if (row == 0)
		{
			return asset_border_top;
		}
		if (col == 0)
		{
			return asset_border_left;
		}
		if (col == boardSize -1)
		{
			return asset_border_right;
		}
		if (row == boardSize -1)
		{
			return asset_border_bottom;
		}
		return asset_common_intersection;
	}

	draw_cell(rowIndex, colIndex)
	{
		var board_state = this.props.board_matrix;
		var board_size = this.props.board_size;
		var idx = board_size * rowIndex + colIndex;
		var color = board_state[idx];
		return (
			<div className="cell" row={rowIndex} col={colIndex} onMouseOver={this.onCellEnter.bind(this)} onMouseOut={this.onCellLeave.bind(this)} onClick={this.props.on_cell_click}>
				<img className="intersection" height='100%' width='100%' src={this.get_intersection_asset(rowIndex, colIndex)}/>
				<img className="black_stone_hint" height='100%' width='100%' style={{visibility:'hidden'}} src={asset_black_stone}/>
				<img className="white_stone_hint" height='100%' width='100%' style={{visibility:'hidden'}} src={asset_white_stone}/>
				<img className="white_stone" height='100%' width='100%' style={{visibility:color==1? 'visible':'hidden'}} src={asset_white_stone}/>
				<img className="black_stone" height='100%' width='100%' style={{visibility:color==2? 'visible':'hidden'}} src={asset_black_stone}/>
			</div>
		);
	}

	render()
	{
		return ( 
			<div className="boardContainer" style={{width:'100%'}}>
			{
				chunk(new Array(this.props.board_size*this.props.board_size), this.props.board_size).map((row, rowIndex) => 
				{
					return (
						<Row key={rowIndex} className={"row"}span={this.props.board_size} justify="center" style={{height:'100%'}}>
							{row.map((col, colIndex) => 
								<Col key={colIndex} className={"col"} span={1} style={{width:'100%'}}>
									{this.draw_cell(rowIndex, colIndex)}
								</Col>)}
						</Row>
					)
				})
			}
			</div>
		);
	}
}

export default GoBoard;