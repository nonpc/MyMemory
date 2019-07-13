function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }

var AnimatedCard = function (_React$Component) {
	_inherits(AnimatedCard, _React$Component);

	function AnimatedCard() {
		_classCallCheck(this, AnimatedCard);

		return _possibleConstructorReturn(this, _React$Component.apply(this, arguments));
	}

	AnimatedCard.prototype.render = function render() {
		var _props = this.props;
		var position = _props.position;
		var digit = _props.digit;
		var animation = _props.animation;

		return React.createElement(
			'div',
			{ className: 'TimeRound ' + position + ' ' + animation },
			React.createElement(
				'span',
				null,
				digit
			)
		);
	};

	return AnimatedCard;
}(React.Component);

var StaticCard = function (_React$Component2) {
	_inherits(StaticCard, _React$Component2);

	function StaticCard() {
		_classCallCheck(this, StaticCard);

		return _possibleConstructorReturn(this, _React$Component2.apply(this, arguments));
	}

	StaticCard.prototype.render = function render() {
		var _props2 = this.props;
		var position = _props2.position;
		var digit = _props2.digit;

		return React.createElement(
			'div',
			{ className: position },
			React.createElement(
				'span',
				null,
				digit
			)
		);
	};

	return StaticCard;
}(React.Component);

var ClockOut = function (_React$Component3) {
	_inherits(ClockOut, _React$Component3);

	function ClockOut() {
		_classCallCheck(this, ClockOut);

		return _possibleConstructorReturn(this, _React$Component3.apply(this, arguments));
	}

	ClockOut.prototype.render = function render() {
		var _props3 = this.props;
		var digit = _props3.digit;
		var shuffle = _props3.shuffle;
		var unit = _props3.unit;

		var now = digit;
		var before = digit - 1;

		if (unit !== 'hours') {
			before = before === -1 ? 59 : before;
		} else {
			before = before === -1 ? 23 : before;
		}

		if (now < 10) now = '0' + now;
		if (before < 10) before = '0' + before;

		var digit1 = shuffle ? before : now;
		var digit2 = !shuffle ? before : now;

		var animation1 = shuffle ? 'Round' : 'UnRound';
		var animation2 = !shuffle ? 'Round' : 'UnRound';

		return React.createElement(
			'div',
			{ className: 'ClockOut' },
			React.createElement(StaticCard, {
				position: 'UpOut',
				digit: now
			}),
			React.createElement(StaticCard, {
				position: 'DownOut',
				digit: before
			}),
			React.createElement(AnimatedCard, {
				position: 'first',
				digit: digit1,
				animation: animation1
			}),
			React.createElement(AnimatedCard, {
				position: 'second',
				digit: digit2,
				animation: animation2
			})
		);
	};

	return ClockOut;
}(React.Component);

var TimeClock = function (_React$Component4) {
	_inherits(TimeClock, _React$Component4);

	function TimeClock(props) {
		_classCallCheck(this, TimeClock);

		var _this4 = _possibleConstructorReturn(this, _React$Component4.call(this, props));

		_this4.state = {
			hours: 0,
			hoursShuffle: true,
			minutes: 0,
			minutesShuffle: true,
			seconds: 0,
			secondsShuffle: true
		};
		return _this4;
	}

	TimeClock.prototype.componentDidMount = function componentDidMount() {
		var _this5 = this;

		this.timerID = setInterval(function () {
			return _this5.updateTime();
		}, 50);
	};

	TimeClock.prototype.componentWillUnmount = function componentWillUnmount() {
		clearInterval(this.timerID);
	};

	TimeClock.prototype.updateTime = function updateTime() {
		// get new date
		var time = new Date();
		// set time units
		var hours = time.getHours();
		var minutes = time.getMinutes();
		var seconds = time.getSeconds();
		// on hour chanage, update this.state.minutes
		if (hours !== this.state.hours) {
			var hoursShuffle = !this.state.hoursShuffle;
			this.setState({
				hours: hours,
				hoursShuffle: hoursShuffle
			});
		}
		// on minute chanage, update this.state.minutes
		if (minutes !== this.state.minutes) {
			var minutesShuffle = !this.state.minutesShuffle;
			this.setState({
				minutes: minutes,
				minutesShuffle: minutesShuffle
			});
		}
		// on second chanage, update this.state.seconds
		if (seconds !== this.state.seconds) {
			var secondsShuffle = !this.state.secondsShuffle;
			this.setState({
				seconds: seconds,
				secondsShuffle: secondsShuffle
			});
		}
	};

	TimeClock.prototype.render = function render() {
		var _state = this.state;
		var hours = _state.hours;
		var minutes = _state.minutes;
		var seconds = _state.seconds;
		var hoursShuffle = _state.hoursShuffle;
		var minutesShuffle = _state.minutesShuffle;
		var secondsShuffle = _state.secondsShuffle;

		return React.createElement(
			'div',
			{ className: 'TimeClock' },
			React.createElement(ClockOut, {
				unit: 'hours',
				digit: hours,
				shuffle: hoursShuffle
			}),
			React.createElement(ClockOut, {
				unit: 'minutes',
				digit: minutes,
				shuffle: minutesShuffle
			}),
			React.createElement(ClockOut, {
				unit: 'seconds',
				digit: seconds,
				shuffle: secondsShuffle
			})
		);
	};

	return TimeClock;
}(React.Component);


var App = function (_React$Component6) {
	_inherits(App, _React$Component6);

	function App() {
		_classCallCheck(this, App);

		return _possibleConstructorReturn(this, _React$Component6.apply(this, arguments));
	}

	App.prototype.render = function render() {
		return React.createElement(
			'div',
			null,
			React.createElement(TimeClock, null)
		);
	};
	return App;
}(React.Component);

ReactDOM.render(React.createElement(App, null), document.querySelector('#time_clock'));



start();
    function start (){
      $("#myCarousel").carousel('cycle');
    }
