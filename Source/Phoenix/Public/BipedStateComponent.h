#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "BaseStateComponent.h"
#include "BipedStateData.h"
#include "BipedStateComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBipedStateComponent : public UBaseStateComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBipedStateData BipedStateData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo TeamAsset;
    
public:
    UBipedStateComponent();
    UFUNCTION(BlueprintCallable)
    void SetTeamName(const FName InTeamName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetTeamName() const;
    
};

