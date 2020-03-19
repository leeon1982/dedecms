<li class="dropdown magz-dropdown"><a href="{dede:field name='typeurl'/}">{dede:field name='typename'/} <i
                class="ion-ios-arrow-right"></i></a>
            <ul class="dropdown-menu">
              {dede:channel type='son' noself='yes'}
              <li><a href="[field:typeurl/]">[field:typename/]</a></li>
              {/dede:channel}
            </ul>
          </li>