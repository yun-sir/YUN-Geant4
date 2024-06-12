#ifndef yunHits_h
#define yunHits_h

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"

class yunHits : public G4VHit
{
    public:
                    yunHits();
                    ~yunHits();

                    inline void *operator new(size_t);
                    inline void operator delete(void* aHit);
                    
                    // void Print() const;

    private:
                    G4double edep;
    
    public: 
                    inline void SetDepositedEnergy(G4double edep_SD) {edep = edep_SD;}
                    inline G4double GetDepositedEnergy() {return edep;}
};

typedef G4THitsCollection<yunHits> yunHitsCollection;

extern G4Allocator<yunHits> yunHitsAllocator;

inline void* yunHits::operator new(size_t)
{
  void* aHit;
  aHit = (void *) yunHitsAllocator.MallocSingle();
  return aHit;
}

inline void yunHits::operator delete(void *aHit)
{
  yunHitsAllocator.FreeSingle((yunHits*) aHit);
}

#endif