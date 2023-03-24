#include "CustomizableActor.h"
#include "CustomizableCharacterComponent.h"
#include "Components/SkeletalMeshComponent.h"

void ACustomizableActor::SetLODOverride(int32 InLODOverride) {
}

FString ACustomizableActor::GetRegistryID() const {
    return TEXT("");
}

UCustomizableCharacterComponent* ACustomizableActor::GetCCC() const {
    return NULL;
}

ACustomizableActor::ACustomizableActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CCC = CreateDefaultSubobject<UCustomizableCharacterComponent>(TEXT("CCC"));
    this->Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("T4Mesh0"));
}

