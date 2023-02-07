#pragma once
#include "CoreMinimal.h"
#include "CreatureMountHandler.h"
#include "CreatureTransformedHandler.generated.h"

UCLASS(Blueprintable)
class ACreatureTransformedHandler : public ACreatureMountHandler {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* RiderCharacterClass;
    
public:
    ACreatureTransformedHandler();
};

