gst-launch-1.0 -v udpsrc port=5000 caps="application/x-rtp, media=video, clock-rate=90000, encoding-name=H264" ! rtph264depay ! avdec_h264 ! autovideosink
