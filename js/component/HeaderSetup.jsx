import React from 'react';

import { Switch } from 'antd';
import { Menu, Button, Slider} from 'antd';
import { Select, Row, Col } from 'antd';
 
const { Option } = Select;

class HeaderSetup extends React.Component
{
  componentWillReceiveProps(nextProps) 
  {
    this.setState( 
    {
      board_size : nextProps.board_size,
      ai_mode : nextProps.ai_mode,
      build_mode : nextProps.build_mode
    }); 
  }

  leftPannel()
  {
    const { board_size, ai_mode, onAIModeChange, onAIAlgorithmChange, onBoardSizeChange,  ...rest } = this.props
    return (
    <div height='100%'>
      <Row align="middle" gutter={[45,0]}>
        <Col>
          AI mode for second player
        </Col>    
        <Col>
          <Switch onChange={onAIModeChange}/>
        </Col>    
      </Row>
      <Row align="middle">
      {
      ai_mode?
        <Col>
          <Select defaultValue="AI Algorithm" shape="round" style={{ width: 250 }} onChange={onAIAlgorithmChange}>
            <Option value="pretree">Predefined tree</Option>
            <Option value="mcts">Monte Carlo Tree Search</Option>
            <Option value="cnn">Convolutional Neural Network</Option>
          </Select>
        </Col>
      :
      <Row align="middle" gutter={[10,0]}>
        <Col>
          Board size
        </Col>
        <Col>
          {<Slider defaultValue={board_size} min={2} max={19} style={{width: 175}} onChange={onBoardSizeChange} />}
        </Col>
      </Row>
      } 
      </Row>      
    </div>);
  }

  middlePannel()
  {
    const { build_mode, onBuildModeChange, onBuildingColorChange, onPresetChange, ...rest } = this.props
    return (
    <div height='100%'>
      <Row align="middle" gutter={[20,0]}>
        <Col span={8}>
          <Button type="primary" shape="round">Load Tsumego</Button>
        </Col>    
        <Col span={8}>
          <Button type="primary" shape="round" onClick={onBuildModeChange}>Build Tsumego</Button>
        </Col>
        <Col span={8}>
          <Button type="primary" shape="round">Reset Tsumego</Button>
        </Col>    
      </Row>
      <Row align="middle" gutter={[20,0]}>
        <Col span={8}>
          <Button type="primary" shape="round">Save Tsumego</Button>
        </Col>
        {
          build_mode?
            <Col span={8}>
              <Switch onChange={onBuildingColorChange} checkedChildren="White stone" unCheckedChildren="Black stone" style={{width:'100%'}}/>
            </Col>
          : 
            <Col span={8}>
              <Select defaultValue="Presets" shape="round" style={{ width: 125 }} onChange={onPresetChange}>
                <Option value="easy1">Easy 01</Option>
                <Option value="easy2">Easy 02</Option>
                <Option value="easy3">Easy 03</Option>
              </Select>
            </Col>
        }
        <Col span={8}>
          <Button type="primary" shape="round">Clear Tsumego</Button>
        </Col> 
      </Row>
    </div>);
  }

  rightPannel()
  {

  }

  render()
  {
    return (
      <Menu theme="dark" mode="horizontal">
        <Row eventKey={0} gutter={[60,0]}>
          <Col eventKey={1} className="leftPannel">
            {this.leftPannel()}
          </Col>
          <Col eventKey={2} className="middlePannel">
            {this.middlePannel()}
          </Col>
          <Col eventKey={3} className="rightPannel">
          </Col>
        </Row>
      </Menu>
    );
  }
}

export default HeaderSetup;