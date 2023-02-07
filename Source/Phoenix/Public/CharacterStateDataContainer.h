#pragma once
#include "CoreMinimal.h"
#include "CharacterStateData.h"
#include "ObjectStateDataContainerBase.h"
#include "CharacterStateDataContainer.generated.h"

UCLASS(Blueprintable, NonTransient)
class PHOENIX_API UCharacterStateDataContainer : public UObjectStateDataContainerBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterStateData Data;
    
    UCharacterStateDataContainer();
};

