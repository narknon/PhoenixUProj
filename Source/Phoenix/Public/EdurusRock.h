#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MunitionType_SubsonicSpell.h"
#include "EdurusRock.generated.h"

UCLASS(Blueprintable)
class AEdurusRock : public AMunitionType_SubsonicSpell {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_RockLaunchDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_RockLaunchSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_RockLaunchAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_RockIdleSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_RockIdleRotationSpeed;
    
public:
    AEdurusRock();
    UFUNCTION(BlueprintCallable)
    void SetRockLaunchDelay(float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetRockIdleLocation(FVector TargetLoc);
    
    UFUNCTION(BlueprintCallable)
    void LaunchRock();
    
};

