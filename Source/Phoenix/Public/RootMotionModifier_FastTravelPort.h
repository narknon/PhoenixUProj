#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifier.h"
#include "RootMotionModifier_FastTravelPort.generated.h"

class USceneComponent;

UCLASS(Blueprintable, NonTransient)
class URootMotionModifier_FastTravelPort : public URootMotionModifier {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<USceneComponent>> TravelerComponents;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<USceneComponent>> PortalComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
public:
    URootMotionModifier_FastTravelPort();
};

