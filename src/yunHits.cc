#include "yunHits.hh"


G4Allocator<yunHits> yunHitsAllocator;

yunHits::yunHits()
:edep(0.)
{}

yunHits::~yunHits()
{}

// void yunHits::Print() const
// {
//     G4cout << this;
//     G4cout << G4endl;
// }