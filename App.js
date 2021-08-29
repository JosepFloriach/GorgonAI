import React from 'react';

import GoBoard from './js/component/GoBoard.jsx';
import HeaderSetup from './js/component/HeaderSetup.jsx'
import gorgon_handler from './js/gorgon_handler.js'

import 'antd/dist/antd.css';
import './css/index.css';

import { Layout} from 'antd';
import { Row, Col } from 'antd';

const { Header, Content, Footer } = Layout;

var default_size = 5;

class App extends React.Component
{
  constructor(props)
  {
    super(props); 
    this.state = 
    {
      board_size : default_size,
      ai_mode : false,
      build_mode : false,
      current_stone_color : 2,
      board_matrix : Array(default_size).fill().map(()=>Array(default_size).fill(0))
    }
    this.gorgon_handler = new gorgon_handler(this);
    this.gorgon_handler.create_board(default_size);
  }

  render() 
  {    
    var self = this;
    return (     
      <Layout className="layout">
          <Header className="header">
            <div className="logo" />
            <HeaderSetup 
              onAIModeChange={self.gorgon_handler.on_ai_mode_changed.bind(self.gorgon_handler)} 
              onAIAlgorithmChange={self.gorgon_handler.on_ai_algorithm_changed.bind(self.gorgon_handler)} 
              onBoardSizeChange={self.gorgon_handler.on_board_size_changed.bind(self.gorgon_handler)} 
              onBuildModeChange={self.gorgon_handler.on_build_mode_changed.bind(self.gorgon_handler)}
              onBuildingColorChange={self.gorgon_handler.on_build_mode_color_changed.bind(self.gorgon_handler)}
              onPresetChange={self.gorgon_handler.on_tsumego_preset_changed.bind(self.gorgon_handler)}
              board_size = {self.state.board_size}
              ai_mode = {self.state.ai_mode}
              build_mode = {self.state.build_mode}
            />
          </Header>
          <Content className="content" style={{padding: '0px 0px'}}>
            <Row style={{height:'100%'}}>
              <Col className="board" span={80}>  
                <GoBoard
                  on_cell_click = {self.gorgon_handler.on_cell_click.bind(self.gorgon_handler)}
                  board_size = {self.state.board_size}
                  ai_mode = {self.state.ai_mode}
                  build_mode = {self.state.build_mode}
                  current_stone_color = {self.state.current_stone_color}
                  board_matrix = {self.state.board_matrix}
                />                
              </Col>
              <Col className="algorithm-visualization" span={80}>
              </Col>
            </Row>            
          </Content>
          <Footer className="footer" style={{ textAlign: 'center' }}>Gorgon Tsumegos AI @2021 Created by Josep Floriach</Footer>
      </Layout>
    );
  }

}

export default App;