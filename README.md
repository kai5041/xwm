# XWM | Waiting for xarch

<p align="center">
  <img src="./xwm_logo.png" alt="XWM Logo" style="width: 200px; height: 200px;"/>
</p>

## Overview
XWM, short for *"Waiting for xarch"* (Japanese: *"xarchを待っている"*), is a C++17-based architecture image loader.  
It can execute any virtualized architecture that implements a `run` function, while providing seamless integration between the host OS and the loaded architecture.  
Supported platforms currently include Linux and Windows, with Android support coming soon.

## Installation
```bash
$ git clone https://github.com/kai5041/xwm.git
$ cd xwm
$ make -j$(nproc)
$ sudo make install # TO BE IMPLEMENTED
```

## Usage

```bash
$ xwm load <image_path> [args...]
# Example: loading 'xarch-origin-x64.linux_img'
$ xwm load ./xarch-origin-x64.linux_img
# This will load the image and execute its 'run' function,
# performing the fetch/decode/execute cycle of xarch's x64 architecture.
```


## Get the SDK #TODO: PROVIDE A PROPER GUIDE

```bash
$ bash -c "$(curl -fsSL https://raw.githubusercontent.com/kai5041/xwm/refs/heads/master/get_sdk.sh)"
```
## Contributing

You can support or contribute to XWM or other projects by donating to the BSC address below or contacting me via [harmonyren.net](https://harmonyren.net/contact-us) (listed as "Kai/解").  
Contributions also help advance the **Open Innovation Collective HARMONY連**.  
More details are available on [HARMONY連's official site](https://harmonyren.net/about-us).  

BSC address: `0x850a059814C88a51B6239F4a5be5cF46c98EB3fa`


## License

License on the way.
