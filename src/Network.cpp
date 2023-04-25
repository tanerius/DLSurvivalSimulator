#include "Network.h"
#include <random>

DLS::Level::Level(int inputs, int outputs)
{
    m_inputNeurons = inputs;
    m_outputNeurons = outputs;

    m_inputs.resize(m_inputNeurons, 0);
    m_outputs.resize(m_outputNeurons, 0);
    m_biases.resize(m_outputNeurons);

    m_weights.resize(m_inputNeurons * m_outputNeurons);

    for (float& n : m_weights) {
        n = randomGen();
    }

    for (float& n : m_biases) {
        n = randomGen();
    }
}

std::vector<int> DLS::Level::FeedForward(const std::vector<int>& inputs)
{
    for (int i = 0; i < inputs.size(); i++)
        m_inputs[i] = inputs[i];
    
    for (int i = 0; i < m_outputs.size(); i++)
    {
        float sum = 0;
        for (int j = 0; j < m_inputs.size(); j++)
            sum += m_inputs[j] * GetWeight(j, i);

        if (sum > m_biases[i])
            m_outputs[i] = 1;
        else
            m_outputs[i] = 0;
    }

    return m_outputs;
}

float DLS::Level::GetWeight(const int inputIndex, const int outputIndex) const
{
    return m_weights[outputIndex * m_weights.size() + inputIndex];
}

float DLS::Level::randomGen() const
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.001);
    float ret = dis(gen);
    if (ret > 1.000f)
        ret = 1.0;
    return ret;
}

void DLS::Level::SetWeight(const int inputIndex, const int outputIndex, const float value)
{
    m_weights[outputIndex * m_weights.size() + inputIndex] = value;
}

// *******

DLS::Network::Network(const std::vector<int>& neuronCounts)
{
    for (int i = 0; i < neuronCounts.size() - 1; i++)
    {
        Level* l = new Level(neuronCounts[i],neuronCounts[i+1]);
        m_levels.push_back(l);
    }
}

std::vector<int> DLS::Network::FeedForward(int level, std::vector<int> inputs)
{
    auto tmpOutputs = m_levels[0]->FeedForward(inputs);

    for(int i=1; i < m_levels.size(); i++)
    {
        tmpOutputs = m_levels[i]->FeedForward(tmpOutputs);
    }

    return tmpOutputs;
    
}