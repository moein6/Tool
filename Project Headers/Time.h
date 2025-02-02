#include <chrono>
#include <thread>


#if __has_include(<iostream>)
#include <iostream>
#endif

using namespace std::chrono_literals;

// This class measures the time spent on tasks.
class Time {
public:
    Time(bool start = false) : isTimerStarted(start), isTimerEnded(false) {
        if (isTimerStarted) {
            m_start = std::chrono::high_resolution_clock::now();
        }
    }

    ~Time() = default;

    void Start() {
        isTimerStarted = true;
        m_start = std::chrono::high_resolution_clock::now();
    }

    void Stop() {
        isTimerEnded = true;
        m_end = std::chrono::high_resolution_clock::now();
    }

    // Program does nothing while sleeping!
    void Sleep(unsigned short milliseconds) const {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }

    friend std::ostream& operator<<(std::ostream& out, const Time& time) {
        if (time.isTimerStarted && time.isTimerEnded) {
            if (time.getDuration() <= 1ms) {
                out << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(time.getDuration()).count() << " ns\n";
            }
            else {
                out << "Time: " << time.getDuration().count() << " s\n";
            }
        }
        else {
            out << "ERROR: Timer has not been stopped.\n";
        }

        return out;
    }

private:
    std::chrono::duration<float> getDuration() const {
        if (isTimerEnded) {
            return std::chrono::duration<float>(m_end - m_start);
        }
        else {
            return std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - m_start);
        }
    }

    std::chrono::high_resolution_clock::time_point m_start, m_end;
    bool isTimerStarted, isTimerEnded;
};
