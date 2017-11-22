#pragma once

#include "portaudio.h"
#include <queue>
#include <stddef.h>
#include <wx/thread.h>
#include "timedbuffer.h"
#include <vector>


class wxEvtHandler;

class Playback
{
    public:
        Playback();
        ~Playback();

        void Init(wxEvtHandler* pManager, unsigned long nBufferSize)
        {
            m_pManager = pManager;
            m_nBufferSize = nBufferSize;

        }


        void Run();

        void SetMixer(const std::vector<char>& vChannels, unsigned int nTotalChannels);
        bool OpenPlayback(unsigned long nDevice, unsigned long nSampleRate, unsigned long nChannels, unsigned long nBufferSize);
        void ClosePlayback();

        bool IsStreamOpen();

        void FlushBuffer();

        unsigned long GetSampleRate() const
        {
            return m_nSampleRate;
        }

        unsigned long GetChannels() const
        {
            return m_nOutputChannels;
        }


        void AddSamples(const timedbuffer* pTimedBuffer);

        const std::vector<char>& GetOutputChannels();

        /** Function called by portaudio when it has received a buffer worth of audio. Checks whether enough audio has been collected and if so does the comparison
        *   @param pBuffer pointer to the buffer containing the audio samples
        *   @param nFrameCount the number of audio frames (2 x number of samples)
        **/
        void Callback(float* pBuffer, size_t nFrameCount);

    protected:

        wxMutex m_mutex;
        bool OpenStream(unsigned long nDevice, unsigned long nSampleRate, PaStreamCallback *streamCallback);
        pairTime_t ConvertDoubleToPairTime(double dTime);
        double ConvertPairTimeToDouble(const pairTime_t& tv);
        void Close();

        wxEvtHandler* m_pManager;

        unsigned long m_nDevice;
        PaStream* m_pStream;                ///< pointer to the PaStream tha reads in the audio

        unsigned long m_nSampleRate;
        unsigned long m_nBufferSize;
        unsigned long m_nOutputChannels;

        float* m_pBuffer;
        struct timedSample
        {
            timedSample(){}
            timedSample(double dT, double dP, unsigned int nT, float dS) : dTransmission(dT), dPresentation(dP), nTimestamp(nT), dSample(dS){}
            double dTransmission;
            double dPresentation;
            unsigned int nTimestamp;
            float dSample;
        };

        std::queue<timedSample> m_qBuffer;


        std::vector<char> m_vMixer;
        unsigned int m_nInputChannels;

        bool m_bDone;

        size_t m_nBuffer;
        bool m_bFirst;

        bool m_bOpen;
        bool m_bClose;
        double m_dLatency;
};

int playbackCallback( const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData );
