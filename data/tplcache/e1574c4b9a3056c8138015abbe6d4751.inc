<article class="col-md-12 article-list">
							<div class="inner">
								<figure>
									[field:array runphp='yes']@me = (empty(@me['litpic']) ? "" : "<a href='{@me['arcurl']}'><img src='{@me['litpic']}'/></a>"); [/field:array]
								</figure>
								<div class="details">
									<div class="detail">
										<div class="category">
											<a href="[field:typelink/]">[field:typename/]</a>
										</div>
										<div class="time">[field:pubdate function="GetDateTimeMK(@me)"/]</div>
									</div>
									<h1><a href="[field:arcurl/]">[field:title/]</a>
									</h1>
									<p>
										[field:description/]...
									</p>
									<footer>
										<a href="#" class="love"><i class="ion-android-favorite-outline"></i>
											<div>[field:click/]</div>
										</a>
										<a href="#" class="love"><i class="ion-android-eye-outline"></i>
											<div>[field:scores/]</div>
										</a>
										<a class="btn btn-primary more" href="[field:arcurl/]">
											<div>详细...</div>
											<div><i class="ion-ios-arrow-thin-right"></i></div>
										</a>
									</footer>
								</div>
							</div>
						</article>