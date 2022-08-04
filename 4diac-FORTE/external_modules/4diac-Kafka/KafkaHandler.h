


#ifndef KAFKAHANDLER_H_
#define KAFKAHANDLER_H_

#include <extevhan.h>
#include <fortelist.h>
#include <KafkaComLayer.h>
#include <forte_sync.h>
#include <forte_string.h>
#include <forte_thread.h>
#include <forte_sem.h>
#include <fortelist.h>
#include <string>
#include <rdkafkacpp.h>

class KafkaHandler : public CExternalEventHandler, public CThread {
    DECLARE_HANDLER(KafkaHandler)
public:
    virtual void registerLayer(KafkaComLayer* paLayer);
    virtual void unregisterLayer(KafkaComLayer* paLayer);

    virtual void enableHandler(void);
    /*!\brief Disable this event source
     */
    virtual void disableHandler(void);
    /*!\brief Sets the priority of the event source
     *
     * \param pa_nPriority new priority of the event source
     */
    virtual void setPriority(int pa_nPriority);
    /*!\brief Get the current priority of the event source
     *
     * \return current priority
     */
    virtual int getPriority(void) const;

protected:
    virtual void run();

private:
    static CSyncObject smKafkaMutex;

    static forte::arch::CSemaphore mStateSemaphore;
    static bool mIsSemaphoreEmpty;
    virtual void resumeSuspend();
    virtual void selfSuspend();
    virtual void addRegisteredLayers();
    virtual void removeDerigesteredLayers();

    int32_t partition = 0;

    typedef std::vector<KafkaComLayer *> KafkaFBContainer;
    std::vector<KafkaComLayer *> m_toAdd;
    std::vector<KafkaComLayer *> m_toRemove;
    KafkaFBContainer m_lstKafkaFBList;
};

#endif 
