#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Node() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__Node__init(msg: *mut Node) -> bool;
    fn tensegrity_interfaces__msg__Node__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Node>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__Node__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Node>);
    fn tensegrity_interfaces__msg__Node__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Node>, out_seq: *mut rosidl_runtime_rs::Sequence<Node>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__Node
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// this is a timestamped message that contains an array of sensor information

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__Node__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__Node__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Node {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Node__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Node__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Node__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Node {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Node where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/Node";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Node() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Motor() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__Motor__init(msg: *mut Motor) -> bool;
    fn tensegrity_interfaces__msg__Motor__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Motor>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__Motor__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Motor>);
    fn tensegrity_interfaces__msg__Motor__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Motor>, out_seq: *mut rosidl_runtime_rs::Sequence<Motor>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__Motor
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// each motor has a unique id and specifies its target length, current position, and commanded speed.  Speed is positive if the motor is extending and negative if it is contracting.  Done is true if the motor has reached the target within the tolerance.  The three error terms (proportional, derivative, and cumulative) are those used in the PID calculation for this motor.  The other two fields are the raw encoder counts and the tendon length as measured by the encoder, taking into account the encoder's resolution, the gear ratio, and the winch diameter.

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__Motor__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__Motor__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Motor {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Motor__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Motor__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Motor__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Motor {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Motor where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/Motor";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Motor() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Info() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__Info__init(msg: *mut Info) -> bool;
    fn tensegrity_interfaces__msg__Info__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Info>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__Info__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Info>);
    fn tensegrity_interfaces__msg__Info__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Info>, out_seq: *mut rosidl_runtime_rs::Sequence<Info>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__Info
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ROS2: field names lowercase per ROS2 convention

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__Info__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__Info__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Info {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Info__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Info__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Info__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Info {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Info where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/Info";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Info() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Sensor() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__Sensor__init(msg: *mut Sensor) -> bool;
    fn tensegrity_interfaces__msg__Sensor__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Sensor>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__Sensor__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Sensor>);
    fn tensegrity_interfaces__msg__Sensor__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Sensor>, out_seq: *mut rosidl_runtime_rs::Sequence<Sensor>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__Sensor
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// each sensor has a unique id and specifies its length in millimeters and capacitance in picofarads

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__Sensor__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__Sensor__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Sensor {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Sensor__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Sensor__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Sensor__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Sensor {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Sensor where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/Sensor";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Sensor() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Imu() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__Imu__init(msg: *mut Imu) -> bool;
    fn tensegrity_interfaces__msg__Imu__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Imu>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__Imu__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Imu>);
    fn tensegrity_interfaces__msg__Imu__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Imu>, out_seq: *mut rosidl_runtime_rs::Sequence<Imu>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__Imu
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// the global orientation of the bar according to the IMU
/// this message encodes a unit vector pointing in the y-direction of the IMU given by id

#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__Imu__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__Imu__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Imu {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Imu__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Imu__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Imu__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Imu {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Imu where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/Imu";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Imu() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__MotorsStamped() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__MotorsStamped__init(msg: *mut MotorsStamped) -> bool;
    fn tensegrity_interfaces__msg__MotorsStamped__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MotorsStamped>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__MotorsStamped__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MotorsStamped>);
    fn tensegrity_interfaces__msg__MotorsStamped__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MotorsStamped>, out_seq: *mut rosidl_runtime_rs::Sequence<MotorsStamped>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__MotorsStamped
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// this is a timestamped message that contains an array of motor control information

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MotorsStamped {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub info: super::super::msg::rmw::Info,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motors: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Motor>,

}



impl Default for MotorsStamped {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__MotorsStamped__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__MotorsStamped__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MotorsStamped {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__MotorsStamped__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__MotorsStamped__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__MotorsStamped__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MotorsStamped {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MotorsStamped where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/MotorsStamped";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__MotorsStamped() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__SensorsStamped() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__SensorsStamped__init(msg: *mut SensorsStamped) -> bool;
    fn tensegrity_interfaces__msg__SensorsStamped__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SensorsStamped>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__SensorsStamped__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SensorsStamped>);
    fn tensegrity_interfaces__msg__SensorsStamped__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SensorsStamped>, out_seq: *mut rosidl_runtime_rs::Sequence<SensorsStamped>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__SensorsStamped
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// this is a timestamped message that contains an array of sensor information

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SensorsStamped {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sensors: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Sensor>,

}



impl Default for SensorsStamped {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__SensorsStamped__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__SensorsStamped__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SensorsStamped {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__SensorsStamped__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__SensorsStamped__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__SensorsStamped__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SensorsStamped {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SensorsStamped where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/SensorsStamped";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__SensorsStamped() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__ImuStamped() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__ImuStamped__init(msg: *mut ImuStamped) -> bool;
    fn tensegrity_interfaces__msg__ImuStamped__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ImuStamped>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__ImuStamped__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ImuStamped>);
    fn tensegrity_interfaces__msg__ImuStamped__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ImuStamped>, out_seq: *mut rosidl_runtime_rs::Sequence<ImuStamped>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__ImuStamped
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// the acceleration in x,y,z and the global orientation angles from the IMU

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ImuStamped {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub imus: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Imu>,

}



impl Default for ImuStamped {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__ImuStamped__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__ImuStamped__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ImuStamped {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__ImuStamped__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__ImuStamped__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__ImuStamped__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ImuStamped {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ImuStamped where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/ImuStamped";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__ImuStamped() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__NodesStamped() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__NodesStamped__init(msg: *mut NodesStamped) -> bool;
    fn tensegrity_interfaces__msg__NodesStamped__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NodesStamped>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__NodesStamped__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NodesStamped>);
    fn tensegrity_interfaces__msg__NodesStamped__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NodesStamped>, out_seq: *mut rosidl_runtime_rs::Sequence<NodesStamped>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__NodesStamped
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// this is a timestamped message that contains an array of sensor information

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NodesStamped {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reconstructed_nodes: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Node>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mocap_nodes: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Node>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub imus: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Imu>,

}



impl Default for NodesStamped {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__NodesStamped__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__NodesStamped__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NodesStamped {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__NodesStamped__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__NodesStamped__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__NodesStamped__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NodesStamped {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NodesStamped where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/NodesStamped";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__NodesStamped() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__StampedIndex() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__StampedIndex__init(msg: *mut StampedIndex) -> bool;
    fn tensegrity_interfaces__msg__StampedIndex__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<StampedIndex>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__StampedIndex__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<StampedIndex>);
    fn tensegrity_interfaces__msg__StampedIndex__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<StampedIndex>, out_seq: *mut rosidl_runtime_rs::Sequence<StampedIndex>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__StampedIndex
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct StampedIndex {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,

}



impl Default for StampedIndex {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__StampedIndex__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__StampedIndex__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for StampedIndex {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__StampedIndex__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__StampedIndex__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__StampedIndex__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for StampedIndex {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for StampedIndex where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/StampedIndex";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__StampedIndex() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Trajectory() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__Trajectory__init(msg: *mut Trajectory) -> bool;
    fn tensegrity_interfaces__msg__Trajectory__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Trajectory>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__Trajectory__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Trajectory>);
    fn tensegrity_interfaces__msg__Trajectory__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Trajectory>, out_seq: *mut rosidl_runtime_rs::Sequence<Trajectory>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__Trajectory
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This is a message that represents the trajectory following and MPC predictions for a tensegrity robot.  Trajectory is a sequence of points along the desired trajectory.  coms is a sequence of predicted centers of mass for the robot.  pas is a sequence of predicted principal axis unit vectors.  This message depends on geometry_msgs/Point

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Trajectory {

    // This member is not documented.
    #[allow(missing_docs)]
    pub trajectory: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub coms: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pas: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub trajectory_segment: i8,

}



impl Default for Trajectory {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__Trajectory__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__Trajectory__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Trajectory {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Trajectory__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Trajectory__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Trajectory__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Trajectory {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Trajectory where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/Trajectory";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Trajectory() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__TensegrityStamped() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__TensegrityStamped__init(msg: *mut TensegrityStamped) -> bool;
    fn tensegrity_interfaces__msg__TensegrityStamped__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TensegrityStamped>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__TensegrityStamped__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TensegrityStamped>);
    fn tensegrity_interfaces__msg__TensegrityStamped__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TensegrityStamped>, out_seq: *mut rosidl_runtime_rs::Sequence<TensegrityStamped>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__TensegrityStamped
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// this is a timestamped message that contains an array of motor control information

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TensegrityStamped {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub info: super::super::msg::rmw::Info,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motors: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Motor>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub sensors: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Sensor>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub imus: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Imu>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub nodes: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Node>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub trajectory: super::super::msg::rmw::Trajectory,


    // This member is not documented.
    #[allow(missing_docs)]
    pub actions: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}



impl Default for TensegrityStamped {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__TensegrityStamped__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__TensegrityStamped__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TensegrityStamped {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__TensegrityStamped__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__TensegrityStamped__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__TensegrityStamped__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TensegrityStamped {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TensegrityStamped where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/TensegrityStamped";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__TensegrityStamped() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__State() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__State__init(msg: *mut State) -> bool;
    fn tensegrity_interfaces__msg__State__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<State>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__State__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<State>);
    fn tensegrity_interfaces__msg__State__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<State>, out_seq: *mut rosidl_runtime_rs::Sequence<State>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__State
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This is a message that represents state of a tensegrity robot to be passed to a model-predictive controller.  Trajectory is a sequence of waypoints along the desired trajectory.  prev_action is the previous action that MPC will use as a key to its internal lookup table.  reverse_the_gait is a boolean that tells the planner if the robot is rolling forward or backward during this segment of the trajectory.  This message depends on geometry_msgs/Point.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct State {

    // This member is not documented.
    #[allow(missing_docs)]
    pub trajectory: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub prev_action: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub reverse_the_gait: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bar_height_changed: bool,

}



impl Default for State {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__State__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__State__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for State {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__State__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__State__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__State__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for State {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for State where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/State";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__State() }
  }
}


#[link(name = "tensegrity_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Action() -> *const std::ffi::c_void;
}

#[link(name = "tensegrity_interfaces__rosidl_generator_c")]
extern "C" {
    fn tensegrity_interfaces__msg__Action__init(msg: *mut Action) -> bool;
    fn tensegrity_interfaces__msg__Action__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Action>, size: usize) -> bool;
    fn tensegrity_interfaces__msg__Action__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Action>);
    fn tensegrity_interfaces__msg__Action__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Action>, out_seq: *mut rosidl_runtime_rs::Sequence<Action>) -> bool;
}

// Corresponds to tensegrity_interfaces__msg__Action
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// This is a message that represents the MPC-selected actions for a tensegrity robot.  The variable actions is a sequence of k strings that represent the depth-k motion plan from MPC.  coms and pas are the current center of mass and principal axis plus the k predicted future coms and pas corresponding to the selected sequence of actions. This message depends on geometry_msgs/Point.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action {

    // This member is not documented.
    #[allow(missing_docs)]
    pub actions: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cost: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub coms: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pas: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub endcaps: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::Point>,


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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !tensegrity_interfaces__msg__Action__init(&mut msg as *mut _) {
        panic!("Call to tensegrity_interfaces__msg__Action__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Action {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Action__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Action__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { tensegrity_interfaces__msg__Action__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Action {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Action where Self: Sized {
  const TYPE_NAME: &'static str = "tensegrity_interfaces/msg/Action";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__tensegrity_interfaces__msg__Action() }
  }
}


