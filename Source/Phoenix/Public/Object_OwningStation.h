#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Object_OwningStation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UObject_OwningStation : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* FindOwningStationFor;
    
    UObject_OwningStation();
};

