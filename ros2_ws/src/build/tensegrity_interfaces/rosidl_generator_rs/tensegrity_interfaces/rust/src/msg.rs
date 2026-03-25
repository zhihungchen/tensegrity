#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to tensegrity_interfaces__msg__Node
/// this is a timestamped message that contains an array of sensor information

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Node {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub z: f64,

}



impl Default for Node {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Node::default())
  }
}

impl rosidl_runtime_rs::Message for Node {
  type RmwMsg = super::msg::rmw::Node;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        x: msg.x,
        y: msg.y,
        z: msg.z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      x: msg.x,
      y: msg.y,
      z: msg.z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      x: msg.x,
      y: msg.y,
      z: msg.z,
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__Motor
/// each motor has a unique id and specifies its target length, current position, and commanded speed.  Speed is positive if the motor is extending and negative if it is contracting.  Done is true if the motor has reached the target within the tolerance.  The three error terms (proportional, derivative, and cumulative) are those used in the PID calculation for this motor.  The other two fields are the raw encoder counts and the tendon length as measured by the encoder, taking into account the encoder's resolution, the gear ratio, and the winch diameter.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Motor {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub done: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub error: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub d_error: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cum_error: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub encoder_counts: i64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub encoder_length: f64,

}



impl Default for Motor {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Motor::default())
  }
}

impl rosidl_runtime_rs::Message for Motor {
  type RmwMsg = super::msg::rmw::Motor;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        position: msg.position,
        target: msg.target,
        speed: msg.speed,
        done: msg.done,
        error: msg.error,
        d_error: msg.d_error,
        cum_error: msg.cum_error,
        encoder_counts: msg.encoder_counts,
        encoder_length: msg.encoder_length,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      position: msg.position,
      target: msg.target,
      speed: msg.speed,
      done: msg.done,
      error: msg.error,
      d_error: msg.d_error,
      cum_error: msg.cum_error,
      encoder_counts: msg.encoder_counts,
      encoder_length: msg.encoder_length,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      position: msg.position,
      target: msg.target,
      speed: msg.speed,
      done: msg.done,
      error: msg.error,
      d_error: msg.d_error,
      cum_error: msg.cum_error,
      encoder_counts: msg.encoder_counts,
      encoder_length: msg.encoder_length,
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__Info
/// ROS2: field names lowercase per ROS2 convention

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Info {

    // This member is not documented.
    #[allow(missing_docs)]
    pub min_length: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub range: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_range: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub min_range: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub range024: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub range135: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub max_speed: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tol: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub low_tol: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub i: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub d: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub dist_weight: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ang_weight: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub prog_weight: f64,

}



impl Default for Info {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Info::default())
  }
}

impl rosidl_runtime_rs::Message for Info {
  type RmwMsg = super::msg::rmw::Info;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        min_length: msg.min_length,
        range: msg.range,
        max_range: msg.max_range,
        min_range: msg.min_range,
        range024: msg.range024,
        range135: msg.range135,
        max_speed: msg.max_speed,
        tol: msg.tol,
        low_tol: msg.low_tol,
        p: msg.p,
        i: msg.i,
        d: msg.d,
        dist_weight: msg.dist_weight,
        ang_weight: msg.ang_weight,
        prog_weight: msg.prog_weight,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      min_length: msg.min_length,
      range: msg.range,
      max_range: msg.max_range,
      min_range: msg.min_range,
      range024: msg.range024,
      range135: msg.range135,
      max_speed: msg.max_speed,
      tol: msg.tol,
      low_tol: msg.low_tol,
      p: msg.p,
      i: msg.i,
      d: msg.d,
      dist_weight: msg.dist_weight,
      ang_weight: msg.ang_weight,
      prog_weight: msg.prog_weight,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      min_length: msg.min_length,
      range: msg.range,
      max_range: msg.max_range,
      min_range: msg.min_range,
      range024: msg.range024,
      range135: msg.range135,
      max_speed: msg.max_speed,
      tol: msg.tol,
      low_tol: msg.low_tol,
      p: msg.p,
      i: msg.i,
      d: msg.d,
      dist_weight: msg.dist_weight,
      ang_weight: msg.ang_weight,
      prog_weight: msg.prog_weight,
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__Sensor
/// each sensor has a unique id and specifies its length in millimeters and capacitance in picofarads

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Sensor {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i8,

    /// mm
    pub length: f32,

    /// pf
    pub capacitance: f32,

}



impl Default for Sensor {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Sensor::default())
  }
}

impl rosidl_runtime_rs::Message for Sensor {
  type RmwMsg = super::msg::rmw::Sensor;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        length: msg.length,
        capacitance: msg.capacitance,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      length: msg.length,
      capacitance: msg.capacitance,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      length: msg.length,
      capacitance: msg.capacitance,
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__Imu
/// the global orientation of the bar according to the IMU
/// this message encodes a unit vector pointing in the y-direction of the IMU given by id

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Imu {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub z: f64,

    /// float64 q1
    /// float64 q2
    /// float64 q3
    /// float64 q4
    pub ax: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ay: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub az: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gx: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gy: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gz: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mx: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub my: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mz: f64,

}



impl Default for Imu {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Imu::default())
  }
}

impl rosidl_runtime_rs::Message for Imu {
  type RmwMsg = super::msg::rmw::Imu;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        x: msg.x,
        y: msg.y,
        z: msg.z,
        ax: msg.ax,
        ay: msg.ay,
        az: msg.az,
        gx: msg.gx,
        gy: msg.gy,
        gz: msg.gz,
        mx: msg.mx,
        my: msg.my,
        mz: msg.mz,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
      x: msg.x,
      y: msg.y,
      z: msg.z,
      ax: msg.ax,
      ay: msg.ay,
      az: msg.az,
      gx: msg.gx,
      gy: msg.gy,
      gz: msg.gz,
      mx: msg.mx,
      my: msg.my,
      mz: msg.mz,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      x: msg.x,
      y: msg.y,
      z: msg.z,
      ax: msg.ax,
      ay: msg.ay,
      az: msg.az,
      gx: msg.gx,
      gy: msg.gy,
      gz: msg.gz,
      mx: msg.mx,
      my: msg.my,
      mz: msg.mz,
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__MotorsStamped
/// this is a timestamped message that contains an array of motor control information

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MotorsStamped {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub info: super::msg::Info,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motors: Vec<super::msg::Motor>,

}



impl Default for MotorsStamped {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MotorsStamped::default())
  }
}

impl rosidl_runtime_rs::Message for MotorsStamped {
  type RmwMsg = super::msg::rmw::MotorsStamped;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        info: super::msg::Info::into_rmw_message(std::borrow::Cow::Owned(msg.info)).into_owned(),
        motors: msg.motors
          .into_iter()
          .map(|elem| super::msg::Motor::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        info: super::msg::Info::into_rmw_message(std::borrow::Cow::Borrowed(&msg.info)).into_owned(),
        motors: msg.motors
          .iter()
          .map(|elem| super::msg::Motor::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      info: super::msg::Info::from_rmw_message(msg.info),
      motors: msg.motors
          .into_iter()
          .map(super::msg::Motor::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__SensorsStamped
/// this is a timestamped message that contains an array of sensor information

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SensorsStamped {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sensors: Vec<super::msg::Sensor>,

}



impl Default for SensorsStamped {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SensorsStamped::default())
  }
}

impl rosidl_runtime_rs::Message for SensorsStamped {
  type RmwMsg = super::msg::rmw::SensorsStamped;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        sensors: msg.sensors
          .into_iter()
          .map(|elem| super::msg::Sensor::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        sensors: msg.sensors
          .iter()
          .map(|elem| super::msg::Sensor::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      sensors: msg.sensors
          .into_iter()
          .map(super::msg::Sensor::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__ImuStamped
/// the acceleration in x,y,z and the global orientation angles from the IMU

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ImuStamped {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub imus: Vec<super::msg::Imu>,

}



impl Default for ImuStamped {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ImuStamped::default())
  }
}

impl rosidl_runtime_rs::Message for ImuStamped {
  type RmwMsg = super::msg::rmw::ImuStamped;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        imus: msg.imus
          .into_iter()
          .map(|elem| super::msg::Imu::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        imus: msg.imus
          .iter()
          .map(|elem| super::msg::Imu::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      imus: msg.imus
          .into_iter()
          .map(super::msg::Imu::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__NodesStamped
/// this is a timestamped message that contains an array of sensor information

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NodesStamped {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reconstructed_nodes: Vec<super::msg::Node>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mocap_nodes: Vec<super::msg::Node>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub imus: Vec<super::msg::Imu>,

}



impl Default for NodesStamped {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NodesStamped::default())
  }
}

impl rosidl_runtime_rs::Message for NodesStamped {
  type RmwMsg = super::msg::rmw::NodesStamped;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        reconstructed_nodes: msg.reconstructed_nodes
          .into_iter()
          .map(|elem| super::msg::Node::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        mocap_nodes: msg.mocap_nodes
          .into_iter()
          .map(|elem| super::msg::Node::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        imus: msg.imus
          .into_iter()
          .map(|elem| super::msg::Imu::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        reconstructed_nodes: msg.reconstructed_nodes
          .iter()
          .map(|elem| super::msg::Node::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        mocap_nodes: msg.mocap_nodes
          .iter()
          .map(|elem| super::msg::Node::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        imus: msg.imus
          .iter()
          .map(|elem| super::msg::Imu::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      reconstructed_nodes: msg.reconstructed_nodes
          .into_iter()
          .map(super::msg::Node::from_rmw_message)
          .collect(),
      mocap_nodes: msg.mocap_nodes
          .into_iter()
          .map(super::msg::Node::from_rmw_message)
          .collect(),
      imus: msg.imus
          .into_iter()
          .map(super::msg::Imu::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__StampedIndex

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StampedIndex {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,

}



impl Default for StampedIndex {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::StampedIndex::default())
  }
}

impl rosidl_runtime_rs::Message for StampedIndex {
  type RmwMsg = super::msg::rmw::StampedIndex;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        id: msg.id,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      id: msg.id,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      id: msg.id,
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__Trajectory
/// This is a message that represents the trajectory following and MPC predictions for a tensegrity robot.  Trajectory is a sequence of points along the desired trajectory.  coms is a sequence of predicted centers of mass for the robot.  pas is a sequence of predicted principal axis unit vectors.  This message depends on geometry_msgs/Point

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Trajectory {

    // This member is not documented.
    #[allow(missing_docs)]
    pub trajectory: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub coms: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pas: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub trajectory_segment: i8,

}



impl Default for Trajectory {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Trajectory::default())
  }
}

impl rosidl_runtime_rs::Message for Trajectory {
  type RmwMsg = super::msg::rmw::Trajectory;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        trajectory: msg.trajectory
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        coms: msg.coms
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        pas: msg.pas
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        trajectory_segment: msg.trajectory_segment,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        trajectory: msg.trajectory
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        coms: msg.coms
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        pas: msg.pas
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      trajectory_segment: msg.trajectory_segment,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      trajectory: msg.trajectory
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      coms: msg.coms
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      pas: msg.pas
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      trajectory_segment: msg.trajectory_segment,
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__TensegrityStamped
/// this is a timestamped message that contains an array of motor control information

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TensegrityStamped {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub info: super::msg::Info,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motors: Vec<super::msg::Motor>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sensors: Vec<super::msg::Sensor>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub imus: Vec<super::msg::Imu>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub nodes: Vec<super::msg::Node>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub trajectory: super::msg::Trajectory,


    // This member is not documented.
    #[allow(missing_docs)]
    pub actions: Vec<std::string::String>,

}



impl Default for TensegrityStamped {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TensegrityStamped::default())
  }
}

impl rosidl_runtime_rs::Message for TensegrityStamped {
  type RmwMsg = super::msg::rmw::TensegrityStamped;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        info: super::msg::Info::into_rmw_message(std::borrow::Cow::Owned(msg.info)).into_owned(),
        motors: msg.motors
          .into_iter()
          .map(|elem| super::msg::Motor::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        sensors: msg.sensors
          .into_iter()
          .map(|elem| super::msg::Sensor::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        imus: msg.imus
          .into_iter()
          .map(|elem| super::msg::Imu::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        nodes: msg.nodes
          .into_iter()
          .map(|elem| super::msg::Node::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        trajectory: super::msg::Trajectory::into_rmw_message(std::borrow::Cow::Owned(msg.trajectory)).into_owned(),
        actions: msg.actions
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        info: super::msg::Info::into_rmw_message(std::borrow::Cow::Borrowed(&msg.info)).into_owned(),
        motors: msg.motors
          .iter()
          .map(|elem| super::msg::Motor::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        sensors: msg.sensors
          .iter()
          .map(|elem| super::msg::Sensor::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        imus: msg.imus
          .iter()
          .map(|elem| super::msg::Imu::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        nodes: msg.nodes
          .iter()
          .map(|elem| super::msg::Node::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        trajectory: super::msg::Trajectory::into_rmw_message(std::borrow::Cow::Borrowed(&msg.trajectory)).into_owned(),
        actions: msg.actions
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      info: super::msg::Info::from_rmw_message(msg.info),
      motors: msg.motors
          .into_iter()
          .map(super::msg::Motor::from_rmw_message)
          .collect(),
      sensors: msg.sensors
          .into_iter()
          .map(super::msg::Sensor::from_rmw_message)
          .collect(),
      imus: msg.imus
          .into_iter()
          .map(super::msg::Imu::from_rmw_message)
          .collect(),
      nodes: msg.nodes
          .into_iter()
          .map(super::msg::Node::from_rmw_message)
          .collect(),
      trajectory: super::msg::Trajectory::from_rmw_message(msg.trajectory),
      actions: msg.actions
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__State
/// This is a message that represents state of a tensegrity robot to be passed to a model-predictive controller.  Trajectory is a sequence of waypoints along the desired trajectory.  prev_action is the previous action that MPC will use as a key to its internal lookup table.  reverse_the_gait is a boolean that tells the planner if the robot is rolling forward or backward during this segment of the trajectory.  This message depends on geometry_msgs/Point.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct State {

    // This member is not documented.
    #[allow(missing_docs)]
    pub trajectory: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub prev_action: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reverse_the_gait: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bar_height_changed: bool,

}



impl Default for State {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::State::default())
  }
}

impl rosidl_runtime_rs::Message for State {
  type RmwMsg = super::msg::rmw::State;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        trajectory: msg.trajectory
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        prev_action: msg.prev_action.as_str().into(),
        reverse_the_gait: msg.reverse_the_gait,
        bar_height_changed: msg.bar_height_changed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        trajectory: msg.trajectory
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        prev_action: msg.prev_action.as_str().into(),
      reverse_the_gait: msg.reverse_the_gait,
      bar_height_changed: msg.bar_height_changed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      trajectory: msg.trajectory
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      prev_action: msg.prev_action.to_string(),
      reverse_the_gait: msg.reverse_the_gait,
      bar_height_changed: msg.bar_height_changed,
    }
  }
}


// Corresponds to tensegrity_interfaces__msg__Action
/// This is a message that represents the MPC-selected actions for a tensegrity robot.  The variable actions is a sequence of k strings that represent the depth-k motion plan from MPC.  coms and pas are the current center of mass and principal axis plus the k predicted future coms and pas corresponding to the selected sequence of actions. This message depends on geometry_msgs/Point.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action {

    // This member is not documented.
    #[allow(missing_docs)]
    pub actions: Vec<std::string::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cost: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub coms: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pas: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub endcaps: Vec<geometry_msgs::msg::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub dist_weight: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ang_weight: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub prog_weight: f64,

}



impl Default for Action {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Action::default())
  }
}

impl rosidl_runtime_rs::Message for Action {
  type RmwMsg = super::msg::rmw::Action;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        actions: msg.actions
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        cost: msg.cost,
        coms: msg.coms
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        pas: msg.pas
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        endcaps: msg.endcaps
          .into_iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        dist_weight: msg.dist_weight,
        ang_weight: msg.ang_weight,
        prog_weight: msg.prog_weight,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        actions: msg.actions
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      cost: msg.cost,
        coms: msg.coms
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        pas: msg.pas
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        endcaps: msg.endcaps
          .iter()
          .map(|elem| geometry_msgs::msg::Point::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      dist_weight: msg.dist_weight,
      ang_weight: msg.ang_weight,
      prog_weight: msg.prog_weight,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      actions: msg.actions
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      cost: msg.cost,
      coms: msg.coms
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      pas: msg.pas
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      endcaps: msg.endcaps
          .into_iter()
          .map(geometry_msgs::msg::Point::from_rmw_message)
          .collect(),
      dist_weight: msg.dist_weight,
      ang_weight: msg.ang_weight,
      prog_weight: msg.prog_weight,
    }
  }
}


