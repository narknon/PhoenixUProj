#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OrientToSlerp.h"
#include "PointAtComponent.h"
#include "PointAtActorBaseComponent.generated.h"

class USceneComponent;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPointAtActorBaseComponent : public UPointAtComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Socket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LocalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOrientToSlerp Smoothing;
    
protected:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> SocketComponentPtr;
    
public:
    UPointAtActorBaseComponent();
};

