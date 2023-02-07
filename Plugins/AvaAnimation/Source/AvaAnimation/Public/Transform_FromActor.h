#pragma once
#include "CoreMinimal.h"
#include "EComponentToUse.h"
#include "TransformProvider.h"
#include "Transform_FromActor.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UTransform_FromActor : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComponentToUse ComponentToUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* FallbackTransform;
    
    UTransform_FromActor();
    UFUNCTION(BlueprintCallable)
    void SetupFallback() const;
    
};

