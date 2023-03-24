#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "SeasonOverrideInterface.h"
#include "SeasonOverrideVolume.generated.h"

UCLASS(Abstract, Blueprintable)
class ENVIRONMENTALGLOBALS_API ASeasonOverrideVolume : public AVolume, public ISeasonOverrideInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ASeasonOverrideVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
    
    // Fix for true pure virtual functions not being implemented
};

