#pragma once
#include "CoreMinimal.h"
#include "BaseStateComponent.h"
#include "CharacterStateData.h"
#include "CharacterStateComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterStateComponent : public UBaseStateComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterStateData CharacterStateData;
    
public:
    UCharacterStateComponent();
};

