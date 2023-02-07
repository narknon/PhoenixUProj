#pragma once
#include "CoreMinimal.h"
#include "PhxAnimSharingStateInstance.h"
#include "PhxAnimSharingStateWithNotifyInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UPhxAnimSharingStateWithNotifyInstance : public UPhxAnimSharingStateInstance {
    GENERATED_BODY()
public:
    UPhxAnimSharingStateWithNotifyInstance();
};

