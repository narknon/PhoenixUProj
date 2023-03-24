#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/TargetPoint.h"
#include "ControlTest.generated.h"

class UUserWidget;

UCLASS(Blueprintable)
class AControlTest : public ATargetPoint {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_subjectName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_maxDisplacement;
    
public:
    AControlTest(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetLogWidget(UUserWidget* i_logWidget);
    
    UFUNCTION(BlueprintCallable)
    void SetCommandVelocity(const FVector& i_velocity);
    
};

